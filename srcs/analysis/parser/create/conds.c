/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:32:31 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/30 16:24:23 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

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
		t_i += count_tkns_for_cond(&tkns[t_i], t_len);
		c_len++;
	}
	return (c_len);
}

static int	store_conds(t_cond *conds, const char *src, const t_tkn *tkns,
	const size_t t_end)
{
	size_t	t_i;
	size_t	tmp;
	size_t	c_i;

	c_i = 0;
	t_i = 0;
	while (t_i < t_end)
	{
		if (t_i)
			conds[c_i].type = tkns[t_i++].type;
		tmp = count_tkns_for_cond(&tkns[t_i], t_end - t_i);
		conds[c_i].cmds = create_cmds(src, &tkns[t_i], tmp);
		if (!conds[c_i].cmds)
			return (conds[c_i].type = TAIL, delete_conds(conds), 0);
		t_i += tmp;
		c_i++;
	}
	return (conds[c_i].type = TAIL, 1);
}

t_cond	*create_conds(const char *src, const t_tkn *tkns, size_t t_end)
{
	t_cond	*conds;
	size_t	c_len;

	c_len = count_conds(tkns, t_end);
	conds = malloc(sizeof(t_cond) * (c_len + 1));
	if (!conds)
		return (NULL);
	conds->type = HEAD;
	if (!store_conds(conds, src, tkns, t_end))
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
