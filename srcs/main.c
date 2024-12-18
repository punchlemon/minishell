/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/12/02 16:26:09 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_extend.h"
#include "minishell.h"
#include "ft_printf_stderr.h"
#include "sig.h"

volatile sig_atomic_t	g_signal;

static void	execute(char *line, t_env **env, int *status)
{
	t_cond	*conds;
	int		i;

	add_history(line);
	set_exec_handler(false);
	conds = analysis(line);
	if (conds)
	{
		if (g_signal == SIGINT)
			*status = 130;
		i = -1;
		while (conds[++i].type != TAIL)
		{
			if (conds[i].type == HEAD)
				*status = exe_cmds(conds[i].cmds, env, status);
			else if (conds[i].type == AND_IF && !(*status))
				*status = exe_cmds(conds[i].cmds, env, status);
			else if (*status)
				*status = exe_cmds(conds[i].cmds, env, status);
			if (*status == SIGINT)
				break ;
		}
		delete_conds(conds);
	}
	g_signal = 0;
}

int	main(int argc, char **argv, char **environ)
{
	char	*line;
	t_env	*env;
	int		status;

	status = 0;
	env = make_env_list(environ);
	(void)argc;
	(void)argv;
	while (1)
	{
		set_idle_handler();
		line = readline("\033[32mminishell\033[33m$\033[0m ");
		if (line == NULL)
			return (ft_printf_stderr("exit\n"), exit(status), 0);
		if (*line)
			execute(line, &env, &status);
		free(line);
	}
}
