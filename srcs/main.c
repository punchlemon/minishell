/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/10 16:43:21 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_extend.h"
#include "minishell.h"

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
		line = readline("minishell$ ");
		if (line == NULL)
			return (1);
		if (*line)
		{
			if (!ft_strcmp(line, "exit"))
				return (free(line), rl_clear_history(), 0);
			add_history(line);
			and_or = create_and_or(line);
			if (and_or)
				execute(and_or, environ);
			else
				SYNTAX_ERROR();
		}
		free(line);
	}
}
