/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_conds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:32:31 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/17 13:31:35 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_analysis.h"
#include "t_minishell.h"
#include "delete_parser.h"

static size_t	count_conds(const t_tokens *tokens, size_t i)
{
	int		type;
	size_t	conds_count;

	conds_count = 1;
	while (i < tokens->len)
	{
		type = tokens->data[i].type;
		if (type == LPAREN)
		{
			while (tokens->data[i].type != RPAREN)
				i++;
		}
		else if (type == RPAREN)
			break ;
		else if (type == AND_IF || type == OR_IF)
			conds_count++;
		i++;
	}
	return (conds_count);
}

static int	get_type(const int type, size_t *i)
{
	int	result;

	if (type == AND_IF)
		result = AND;
	else if (type == OR_IF)
		result = OR;
	else
		return (HEAD);
	(*i)++;
	return (result);
}

static t_cond	*store_conds(const char *src, const t_tokens *tokens, size_t *i,
	t_cond *conds)
{
	int		type;
	size_t		conds_i;

	conds_i = 0;
	while (conds[conds_i].type != TAIL)
	{
		conds[conds_i].type = get_type(tokens->data[*i].type, i);
		conds[conds_i].pipeline = create_pipeline(src, tokens, i);
		if (!conds[conds_i].pipeline)
		{
			while (conds_i--)
				delete_cond(conds + conds_i);
			return (free(conds), NULL);
		}
		conds_i++;
	}
	return (conds);
}

t_cond	*create_conds(const char *src, const t_tokens *tokens, size_t *i)
{
	t_cond	*conds;
	size_t	conds_count;

	conds_count = count_conds(tokens, *i);
	conds = malloc(sizeof(t_cond) * (conds_count + 1));
	if (!conds)
		return (free(conds), NULL);
	conds[conds_count].type = TAIL;
	return (store_conds(src, tokens, i, conds));
}
