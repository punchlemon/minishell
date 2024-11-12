/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/11 21:30:20 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_extend.h"
#include "minishell.h"

static void	cleanup_and_exit(char *line)
{
	if (line)
		free(line);
	rl_clear_history();
	clear_history();
	exit (0);
}
// rl_clear_historyとclear_historyの違いがわからん

// static t_red	*expand_reds(t_cmd_a *cmds)
// {
// 	return (NULL);
// }

// static char	*expand_words(t_cmd_a *cmds)
// {
// 	return (NULL);
// }

// static void	execute(t_cond *conds, char **environ)
// {
// 	size_t	i;
// 	int		status;
// 	char	*words;
// 	t_red	*reds;

// 	i = 0;
// 	while (conds[i].type != TAIL)
// 	{
// 		words = expand_words(conds[i].cmds);
// 		reds = expand_reds(conds[i].cmds);
// 		if (conds[i].type == HEAD)
// 			exe(words, environ, &status);
// 		else if (conds[i].type == AND_IF)
// 		{
// 			if (!status)
// 				exe(words, environ, &status);
// 		}
// 		else
// 		{
// 			if (status)
// 				exe(words, environ, &status);
// 		}
// 		i++;
// 	}
// 	delete_conds(conds);
// }

int	main(int argc, char **argv, char **environ)
{
	char	*line;
	t_cond	*conds;

	(void)argc;
	(void)argv;
	(void)environ;
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
			delete_conds(conds);
			// if (conds)
			// 	execute(conds, environ);
		}
		free(line);
	}
}
