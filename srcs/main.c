/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 14:05:12 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	execute_first_cmd(t_and_or *and_or, char **environ, int *status)
{
	if (and_or->op == CMD)
		exe(and_or->pipe->cmd->argv, environ, status);
	else
	{
		put_num(and_or->op);
		exit(1);
	}
}

void	execute_one_cmd(t_and_or *and_or, char **environ, int *status)
{
	if (and_or->op == AND)
	{
		if (!*status)
			exe(and_or->pipe->cmd->argv, environ, status);
	}
	else if (and_or->op == OR)
	{
		if (*status)
			exe(and_or->pipe->cmd->argv, environ, status);
	}
	else
	{
		put_num(and_or->op);
		exit(1);
	}
}

void	execute(t_and_or *and_or, char **environ)
{
	size_t	i;
	int		status;

	i = 0;
	while (and_or)
	{
		if (!and_or->pipe->cmd->argv)
			exit(1);
		if (i == 0)
			execute_first_cmd(and_or, environ, &status);
		else
			execute_one_cmd(and_or, environ, &status);
		and_or = and_or->next;
		i++;
	}
}

int	main(int argc, char **argv, char **environ)
{
	char		*line;
	t_and_or	*and_or;
	int			res;

	res = 0;
	(void)argc;
	(void)argv;
	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL)
			break ;
		if (*line)
			add_history(line);
		if (!ft_strcmp(line, "exit"))
			return (free(line), rl_clear_history(), 0);
		res = analysis(line, &and_or);
		free(line);
		if (res == 1)
			continue ;
		execute(and_or, environ);
		delete_and_or(and_or);
	}
	return (0);
}
