/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:32:31 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/22 12:58:29by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_delete.h"

static size_t	count_conds(const t_tkn *tkns, const size_t t_len)
{
	int		type;
	size_t	t_i;
	size_t	c_count;

	c_count = 0;
	t_i = 0;
	while (t_i < t_len)
	{
		type = tkns[t_i].type;
		if (type == LPAREN)
			t_i += match_paren(tkns + t_i);
		else if (type == AND_IF || type == OR_IF)
			c_count++;
		t_i++;
	}
	c_count++;
	return (c_count);
}

static t_cond	*store_conds(t_cond *conds, const char *src,
	const t_tkn *tkns, const size_t t_len)
{
	int		type;
	size_t	c_i;
	size_t	t_i;
	size_t	c_len;

	c_len = 0;
	c_i = 0;
	t_i = 0;
	conds[c_i].type = HEAD;
	while ((t_i + c_len) < t_len)
	{
		type = tkns[t_i + c_len].type;
		if (type == LPAREN)
			c_len += match_paren(tkns + t_i);
		else if (type == AND_IF || type == OR_IF)
		{
			conds[(c_i)++].cmds = create_cmds(src, tkns + t_i, c_len);
			conds[c_i].type = type;
			t_i += c_len + 1;
			c_len = 0;
		}
		else
			c_len++;
	}
	conds[(c_i)++].cmds = create_cmds(src, tkns + t_i, c_len);
	conds[c_i].type = TAIL;
	return (conds);
}
// 最初にtypeの代入と最後にcreate_cmdsの代入が入ってしまっているのを修正する
// create_pipelineのNULLの処理を入れる
// その後で行数を25行以内にする

t_cond	*create_conds(const char *src, const t_tkn *tkns, const size_t t_len)
{
	t_cond	*conds;
	size_t	c_len;

	c_len = count_conds(tkns, t_len);
	conds = malloc(sizeof(t_cond) * (c_len + 1));
	if (!conds)
		return (NULL);
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
