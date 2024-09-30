/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/30 17:37:48by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_first_cmd(int op, char **argv, char **environ, int *status)
{
	if (op == CMD)
		exe(argv, environ);
	else
		exit(1);
	*status = 0; /// 本来はstatusをexeの結果によって更新する必要がある
}

void	execute_one_cmd(int op, char **argv, char **environ, int *status)
{
	int	status;

	if (op == AND && !*status) /// 前回が成功してる (*status == 0) なら実行する
		exe(argv, environ);
	else if (op == OR && *status) /// 前回が失敗してる (*status != 0) なら実行する
		exe(argv, environ);
	else
		exit(1);
	*status = 0; /// 本来はstatusをexeの結果によって更新する必要がある
}

void	execute(t_cmd_node *cmd_n, char **environ)
{
	char	**argv;
	size_t	i;
	int		status;

	i = 0;
	while (1)
	{
		argv = str_slice_to_char_pntr_array(cmd_n->p_cmd->str_s);
		if (!argv)
			exit(1);
		if (i == 0)
			execute_first_cmd(cmd_n->op, argv, environ, &status);
		else
			execute_one_cmd(cmd_n->op, argv, environ, &status);
		cmd_n = cmd_n->next;
		i++;
	}
}

int	main(int argc, char **argv, char **environ)
{
	char		*line;
	t_cmd_node	*cmd_n;

	(void)argc;
	(void)argv;
	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL)
			break ;
		if (*line)
			add_history(line);
		cmd_n = analysis(line);
		execute(cmd_n, environ);
		delete_cmd_node(cmd_n);
		free(line);
	}
	return (0);
}
