/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:05:07 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/06 19:28:12 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include "minishell.h"

t_and_or	*create_and_or_elm(t_str *str, int op)
{
	t_and_or	*and_or;

	and_or = ft_calloc(sizeof(t_and_or));
	if (!and_or)
		return (NULL);
	and_or->pipe = create_pipe(str);
	if (!and_or->pipe)
		return (free(and_or), NULL);
	and_or->op = op;
	and_or->next = NULL;
	return (and_or);
}

t_and_or	*append_and_or(t_and_or **cmd_n_ref, t_str_list **str_l_ref)
{
	t_and_or	*and_or;
	int			op;

	if (is_equal_str((*str_l_ref)->str, "&&"))
		op = AND;
	else if (is_equal_str((*str_l_ref)->str, "||"))
		op = OR;
	else
		return (put("here\n"), NULL);
	*str_l_ref = (*str_l_ref)->next;
	and_or = create_and_or_elm((*str_l_ref)->str, op);
	if (!and_or)
		return (NULL);
	(*cmd_n_ref)->next = and_or;
	*cmd_n_ref = and_or;
	return (*cmd_n_ref);
}

t_and_or	*create_and_or(t_str_arr *str_s)
{
	t_and_or	*head_n;
	t_and_or	*and_or;
	t_str_list	*head_l;
	t_str_list	*str_l;

	head_l = str_s->list;
	and_or = create_and_or_elm(head_l->str, CMD);
	if (!and_or)
		return (NULL);
	head_n = and_or;
	str_l = head_l->next;
	while (str_l != head_l)
	{
		if (!append_and_or(&and_or, &str_l))
			return (delete_and_or(head_n));
		str_l = str_l->next;
	}
	return (head_n);
}
