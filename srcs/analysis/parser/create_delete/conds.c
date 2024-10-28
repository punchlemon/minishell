/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:32:31 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/28 21:54:36 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_delete.h"

static size_t	count_cond(const t_tkn *tkns, const size_t t_len)
{
	size_t	t_i;

	t_i = 0;
	while (t_i < t_len || tkns[t_i].type == AND_IF || tkns[t_i].type == OR_IF)
	{
		if (tkns[t_i].type == LPAREN)
			t_i += match_paren(&tkns[t_i]);
		t_i++;
	}
	return (t_i);
}

static size_t	count_conds(const t_tkn *tkns, const size_t t_len)
{
	size_t	t_i;
	size_t	c_len;

	c_len = 0;
	t_i = 0;
	while (t_i < t_len)
	{
		if (t_i)
			t_i++;
		t_i += count_cond(&tkns[t_i], t_len);
		c_len++;
	}
	return (c_len);
}

static int	store_conds(t_cond *conds, const char *src, const t_tkn *tkns,
	const size_t t_len)
{
	size_t	t_i;
	size_t	tmp_len;
	size_t	c_i;

	c_i = 0;
	t_i = 0;
	while (t_i < t_len)
	{
		if (t_i)
			conds[c_i].type = tkns[t_i++].type;
		tmp_len = count_cond(&tkns[t_i], t_len);
		conds[c_i].cmds = create_cmds(src, &tkns[t_i], tmp_len);
		if (!conds[c_i].cmds)
			return (conds[c_i].type = TAIL, delete_conds(conds), 0);
		t_i += tmp_len;
		c_i++;
	}
	return (conds[c_i].type = TAIL, 1);
}

t_cond	*create_conds(const char *src, const t_tkn *tkns, size_t t_len)
{
	t_cond	*conds;
	size_t	c_len;

	c_len = count_conds(tkns, t_len);
	conds = malloc(sizeof(t_cond) * (c_len + 1));
	if (!conds)
		return (NULL);
	conds->type = HEAD;
	if (!store_conds(conds, src, tkns, t_len))
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
