/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:13:14 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/04 19:10:33 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include "minishell.h"

t_cmd_node	*create_cmd_node_elm(t_str *str, int op)
{
	t_cmd_node	*cmd_n;

	cmd_n = ft_calloc(sizeof(t_cmd_node));
	if (!cmd_n)
		return (NULL);
	cmd_n->p_cmd = create_pipe_cmd(str);
	if (!cmd_n->p_cmd)
		return (free(cmd_n), NULL);
	cmd_n->op = op;
	cmd_n->next = NULL;
	return (cmd_n);
}

t_cmd_node	*append_cmd_node(t_cmd_node **cmd_n_ref, t_str_list **str_l_ref)
{
	t_cmd_node	*cmd_n;
	int			op;

	if (is_equal_str_src((*str_l_ref)->str, "&&"))
		op = AND;
	else if (is_equal_str_src((*str_l_ref)->str, "||"))
		op = OR;
	else
		return (put("here\n"), NULL);
	*str_l_ref = (*str_l_ref)->next;
	cmd_n = create_cmd_node_elm((*str_l_ref)->str, op);
	if (!cmd_n)
		return (NULL);
	(*cmd_n_ref)->next = cmd_n;
	*cmd_n_ref = cmd_n;
	return (*cmd_n_ref);
}

t_cmd_node	*create_cmd_node(t_str_slice *str_s)
{
	t_cmd_node	*head_n;
	t_cmd_node	*cmd_n;
	t_str_list	*head_l;
	t_str_list	*str_l;

	head_l = str_s->list;
	cmd_n = create_cmd_node_elm(head_l->str, CMD);
	if (!cmd_n)
		return (NULL);
	head_n = cmd_n;
	str_l = head_l->next;
	while (str_l != head_l)
	{
		if (!append_cmd_node(&cmd_n, &str_l))
			return (delete_cmd_node(head_n));
		str_l = str_l->next;
	}
	return (head_n);
}
