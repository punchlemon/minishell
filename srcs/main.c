/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/23 18:37:10 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_extend.h"
#include "minishell.h"
#include "sig.h"

static void	execute(t_cond *conds, t_env **env, int *status)
{
	size_t	i;

	i = 0;
	while (conds[i].type != TAIL)
	{
		if (conds[i].type == HEAD)
		{
			*status = exe_cmds(conds[i].cmds, env, status);
		}
		else if (conds[i].type == AND_IF)
		{
			if (!(*status))
				*status = exe_cmds(conds[i].cmds, env, status);
		}
		else
		{
			if (status)
				*status = exe_cmds(conds[i].cmds, env, status);
		}
		i++;
	}
	delete_conds(conds);
}

int	main(int argc, char **argv, char **environ)
{
	char	*line;
	t_cond	*conds;
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
			exit(status);
		if (*line)
		{
			add_history(line);
			set_exec_handler(false);
			conds = analysis(line);
			if (conds)
				execute(conds, &env, &status);
		}
		free(line);
	}
}
