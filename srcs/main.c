/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/30 21:56:01by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_extend.h"
#include "minishell.h"

// RESET \033[0m
// RED \033[31m
// GREEN \033[32m
// YELLOW \033[33m
// BLUE \033[34m
// MAGENTA \033[35m
// CYAN \033[36m
// WHITE \033[37m

static void	cleanup_and_exit(char *line)
{
	if (line)
		free(line);
	rl_clear_history();
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
			exe(conds[i].cmds[0].words, environ, &status);
		else if (conds[i].type == AND_IF)
		{
			if (!status)
				exe(conds[i].cmds[0].words, environ, &status);
		}
		else
		{
			if (status)
				exe(conds[i].cmds[0].words, environ, &status);
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
			if (conds)
				execute(conds, environ);
		}
		free(line);
	}
}
