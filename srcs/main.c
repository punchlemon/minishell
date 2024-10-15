/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 10:10:55 by retanaka         ###   ########.fr       */
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

// static void	cleanup_and_exit(char *line)
// {
// 	if (line)
// 		free(line);
// 	rl_clear_history();
// 	clear_history();
// 	exit (0);
// }

static void	execute(t_and_or *and_or, char **environ)
{
	size_t	i;
	int		status;

	i = 0;
	while (and_or[i].pipe)
	{
		if (and_or[i].op == CMD)
			exe(and_or[i].pipe->cmd->argv, environ, &status);
		else if (and_or[i].op == AND)
		{
			if (!status)
				exe(and_or[i].pipe->cmd->argv, environ, &status);
		}
		else if (and_or->op == OR)
		{
			if (status)
				exe(and_or[i].pipe->cmd->argv, environ, &status);
		}
		i++;
	}
	delete_and_or(and_or);
}

int	main(int argc, char **argv, char **environ)
{
	char		*line;
	t_and_or	*and_or;

	(void)argc;
	(void)argv;
	while (1)
	{
		line = readline("\033[32mminishell\033[34m$\033[0m ");
		if (line == NULL)
			return (1);
		if (*line)
		{
			// add_history(line);
			// if (!ft_strcmp(line, "exit"))
			// 	cleanup_and_exit(line);
			and_or = analysis(line);
			if (and_or)
				execute(and_or, environ);
		}
		free(line);
	}
}
