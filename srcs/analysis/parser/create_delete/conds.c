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

static size_t	match_paren(const t_token *tokens)
{
	int		type;
	size_t	i;

	i = 1;
	while (1)
	{
		type = tokens[i].type;
		if (type == LPAREN)
			i += match_paren(tokens + i);
		else if (type == RPAREN)
			break ;
		i++;
	}
	return (i);
}

static size_t	count_conds(const t_token *tokens, const size_t t_count)
{
	int		type;
	size_t	t_i;
	size_t	c_count;

	c_count = 0;
	t_i = 0;
	while (t_i < t_count)
	{
		type = tokens[t_i].type;
		if (type == LPAREN)
			t_i += match_paren(tokens + t_i);
		else if (type == AND_IF || type == OR_IF)
			c_count++;
		t_i++;
	}
	c_count++;
	return (c_count);
}

static void	store_conds(t_cond *conds, const char *src, const t_token *tokens,
	const size_t t_count)
{
	int		type;
	size_t	c_i;
	size_t	t_i;
	size_t	p_count;

	p_count = 0;
	c_i = 0;
	t_i = 0;
	conds[c_i].type = HEAD;
	while ((t_i + p_count) < t_count)
	{
		type = tokens[t_i + p_count].type;
		if (type == LPAREN)
			p_count += match_paren(tokens + t_i);
		else if (type == AND_IF || type == OR_IF)
		{
			conds[(c_i)++].pipeline = create_pipeline(src, tokens + t_i, p_count);
			conds[c_i].type = type;
			t_i += p_count + 1;
			p_count = 0;
		}
		else
			p_count++;
	}
	conds[c_i].pipeline = create_pipeline(src, tokens + t_i, p_count);
}
// create_pipelineのNULLの処理を入れる

t_cond	*create_conds(const char *src, const t_token *tokens,
	const size_t t_count)
{
	t_cond	*conds;
	size_t	c_count;

	c_count = count_conds(tokens, t_count);
	conds = malloc(sizeof(t_cond) * (c_count + 1));
	if (!conds)
		return (NULL);
	store_conds(conds, src, tokens, t_count);
	conds[c_count].type = TAIL;
	return (conds);
}

void	delete_conds(t_cond *conds)
{
	size_t	i;

	i = 0;
	while (conds[i].type != TAIL)
	{
		delete_pipeline(conds[i].pipeline);
		i++;
	}
	free(conds);
}
