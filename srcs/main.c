/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/16 12:39:44 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_extend.h"
#include "minishell.h"

// static void	cleanup_and_exit(char *line)
// {
// 	if (line)
// 		free(line);
// 	clear_history();
// 	exit (0);
// }

static void	execute(t_cond *conds, t_env *env)
{
	size_t	i;
	int		status;

	i = 0;
	while (conds[i].type != TAIL)
	{
		if (conds[i].type == HEAD)
		{
			exe_cmds(conds[i].cmds, env, &status);
		}
		else if (conds[i].type == AND_IF)
		{
			if (!status)
				exe_cmds(conds[i].cmds, env, &status);
		}
		else
		{
			if (status)
				exe_cmds(conds[i].cmds, env, &status);
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

	env = make_env_list(environ);
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
			// if (!ft_strcmp(line, "exit"))
			// 	cleanup_and_exit(line);
			conds = analysis(line);
			if (conds)
				execute(conds, env);
		}
		free(line);
	}
}
