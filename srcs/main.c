/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/15 18:28:21 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_extend.h"
#include "minishell.h"
#include "sig.h"

static void	cleanup_and_exit(char *line)
{
	if (line)
		free(line);
	clear_history();
	exit (0);
}

static void	execute(t_cond *conds, char **environ)
{
	size_t	i;
	int		status;

	i = 0;
	while (conds[i].type != TAIL)
	{
		if (conds[i].type == HEAD)
		{
			exe_cmds(conds[i].cmds, environ, &status);
		}
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
		set_idle_handler();
		line = readline("\033[32mminishell\033[33m$\033[0m ");
		if (line == NULL)
		{
			ft_putendl_fd("exit", STDERR_FILENO);
			exit (1);
		}
		if (*line)
		{
			if (!ft_strcmp(line, "exit"))
			{
				ft_putendl_fd("exit", STDERR_FILENO);
				cleanup_and_exit(line);
			}
			add_history(line);
			set_exec_handler(false);
			conds = analysis(line);
			if (conds)
				execute(conds, environ);
		}
		free(line);
	}
}
