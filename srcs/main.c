/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/05 08:50:06 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_extend.h"
#include "minishell.h"

static void	cleanup_and_exit(char *line)
{
	if (line)
		free(line);
	// rl_clear_history();
	clear_history();
	exit (0);
}
// rl_clear_historyとclear_historyの違いがわからん

static void	execute(t_cond *conds, char **environ)
{
	size_t	i;
	int		status;

	i = 0;
	while (conds[i].type != TAIL)
	{
		if (conds[i].type == HEAD)
			exe_cmds(conds[i].cmds, environ, &status);
		else if (conds[i].type == AND_IF)
		{
			if (!status)
				exe_cmds(conds[i].cmds, environ, &status);
		}
		else
		{
			if (status)
				exe_cmds(conds[i].cmds, environ, &status);
		}
		i++;
	}
	delete_conds(conds);
}

int	main(int argc, char **argv, char **environ)
{
	char	*line;
	t_cond	*conds;

	(void)argc;
	(void)argv;
	while (1)
	{
		line = readline("\033[32mminishell\033[33m$\033[0m ");
		if (line == NULL)
			return (1);
		if (*line)
		{
			add_history(line);
			if (!ft_strcmp(line, "exit"))
				cleanup_and_exit(line);
			conds = analysis(line);
			init_conds(conds);
			if (conds)
				execute(conds, environ);
		}
		free(line);
	}
}
