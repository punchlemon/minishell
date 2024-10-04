/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:04:26 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/04 21:16:47 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"

void	print_cmd_node(t_cmd_node *cmd_n)
{
	if (!cmd_n)
		return ((void)put("cmd_n:(null)\n"));
	if (!cmd_n->p_cmd)
		return ((void)put("cmd_n->p_cmd:(null)\n"));
	while (cmd_n)
	{
		put("op:");
		if (cmd_n->op == CMD)
			put("cmd");
		else if (cmd_n->op == AND)
			put("and");
		else if (cmd_n->op == OR)
			put("or");
		put(" ");
		put_str_slice(cmd_n->p_cmd->str_s);
		cmd_n = cmd_n->next;
	}
}
