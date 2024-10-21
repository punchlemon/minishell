/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:22:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 23:20:00 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_analysis.h"
#include "type.h"
#include "libft_extend.h"
#include "store_tokens.h"

static void	store_quote(t_token *tokens, const char *src, size_t *i
	, size_t *t_i)
{
	char	c;

	c = src[(*i)++];
	if (c == '\'')
		tokens[*t_i].type = SINGLE;
	else
		tokens[*t_i].type = DOUBLE;
	tokens[*t_i].head = *i;
	while (src[*i] != c)
		(*i)++;
	tokens[(*t_i)++].tail = ++(*i);
	c = src[*i];
	if (ft_isspace(c))
		while (ft_isspace(src[*i]))
			(*i)++;
	else if (ft_istoken(c) || !c)
		return ;
	else
		store_word(tokens, src, i, t_i);
}

static void	store_normal_word(t_token *tokens, const char *src, size_t *i
	, size_t *t_i)
{
	char	c;

	tokens[*t_i].type = NORMAL;
	tokens[*t_i].head = *i;
	while (1)
	{
		c = src[++(*i)];
		if (ft_isspace(c))
		{
			tokens[(*t_i)++].tail = *i;
			while (ft_isspace(src[*i]))
				(*i)++;
			return ;
		}
		else if (ft_istoken(c) || !c)
			return ((void)(tokens[(*t_i)++].tail = *i));
		else if (c == '"' || c == '\'')
		{
			tokens[(*t_i)++].tail = *i;
			store_quote(tokens, src, i, t_i);
			return ;
		}
	}
}

void	store_word(t_token *tokens, const char *src, size_t *i, size_t *t_i)
{
	if (src[*i] == '"' || src[*i] == '\'')
		store_quote(tokens, src, i, t_i);
	else
		store_normal_word(tokens, src, i, t_i);
}
