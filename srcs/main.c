/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/16 16:41:36 by retanaka         ###   ########.fr       */
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

static void	execute(t_exec_plan *exec_plan, char **environ)
{
	size_t	i;
	int		status;

	i = 0;
	while (i < exec_plan->count)
	{
		if (exec_plan->conds[i].type == CMD)
			exe(exec_plan->conds[i].pipeline[0].normal_cmd->argv, environ, &status);
		else if (exec_plan->conds[i].type == AND)
		{
			if (!status)
				exe(exec_plan->conds[i].pipeline[0].normal_cmd->argv, environ, &status);
		}
		else
		{
			if (status)
				exe(exec_plan->conds[i].pipeline[0].normal_cmd->argv, environ, &status);
		}
		i++;
	}
	delete_exec_plan(exec_plan);
}

int	main(int argc, char **argv, char **environ)
{
	char		*line;
	t_exec_plan	*exec_plan;

	(void)argc;
	(void)argv;
	while (1)
	{
		line = readline("\033[32mminishell\033[34m$\033[0m ");
		if (line == NULL || !ft_strcmp(line, "exit"))
			return (1);
		if (*line)
		{
			// add_history(line);
			// if (!ft_strcmp(line, "exit"))
			// 	cleanup_and_exit(line);
			exec_plan = analysis(line);
			if (exec_plan)
				execute(exec_plan, environ);
		}
		free(line);
	}
}
