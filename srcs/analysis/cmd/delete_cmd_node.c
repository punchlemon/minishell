/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_cmd_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:00:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/30 19:33:19 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*delete_cmd_node(t_cmd_node *cmd_n)
{
	t_cmd_node	*head_n;
	t_cmd_node	*next_n;

	head_n = cmd_n;
	while (1)
	{
		next_n = cmd_n->next;
		cmd_n->op = 0;
		cmd_n->p_cmd = delete_pipe_cmd(cmd_n->p_cmd);
		cmd_n->next = NULL;
		free(cmd_n);
		if (next_n == head_n)
			return (NULL);
		cmd_n = next_n;
	}
}
