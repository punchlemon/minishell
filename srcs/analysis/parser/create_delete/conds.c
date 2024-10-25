/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:32:31 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/25 20:20:19 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_delete.h"

static size_t	count_cond(const t_tkn *head, const t_tkn *tail)
{
	int		type;
	size_t	t_len;

	t_len = 0;
	type = head->type;
	if (type == AND_IF || type == OR_IF)
		t_len++;
	while (1)
	{
		type = head[t_len].type;
		if (type == LPAREN)
			t_len += match_paren(head + t_len);
		else if (type == AND_IF || type == OR_IF || head + t_len == tail)
			break ;
		t_len++;
	}
	return (t_len);
}

static size_t	count_conds(const t_tkn *head, const t_tkn *tail)
{
	size_t	t_i;
	size_t	c_len;

	c_len = 0;
	t_i = 0;
	while (1)
	{
		t_i += count_cond(head + t_i, tail);
		c_len++;
		if (head + t_i == tail)
			return (c_len);
	}
}

static t_cond	*store_conds(t_cond *conds, const char *src, const t_tkn *head,
	const t_tkn *tail)
{
	size_t	old_t_i;
	size_t	new_t_i;
	size_t	c_i;

	c_i = 0;
	old_t_i = 0;
	new_t_i = 0;
	while (1)
	{
		old_t_i = new_t_i;
		if (old_t_i)
			conds->type = head[old_t_i].type;
		new_t_i += count_cond(head + old_t_i, tail);
		conds[c_i].cmds = create_cmds(src, head + old_t_i, head + new_t_i);
		if (!conds[c_i].cmds)
			return (conds[c_i].type = TAIL, delete_conds(conds), NULL);
		c_i++;
		if (head + new_t_i == tail)
			return (conds[c_i].type = TAIL, conds);
	}
}

t_cond	*create_conds(const char *src, const t_tkn *head, const t_tkn *tail)
{
	t_cond	*conds;
	size_t	c_len;

	c_len = count_conds(head, tail);
	conds = malloc(sizeof(t_cond) * (c_len + 1));
	if (!conds)
		return (NULL);
	conds->type = HEAD;
	if (!store_conds(conds, src, head, tail))
		return (NULL);
	return (conds);
}

void	delete_conds(t_cond *conds)
{
	size_t	i;

	i = 0;
	while (conds[i].type != TAIL)
	{
		delete_cmds(conds[i].cmds);
		i++;
	}
	free(conds);
}
