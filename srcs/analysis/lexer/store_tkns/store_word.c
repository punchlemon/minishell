/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:22:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/30 01:28:32 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_analysis.h"
#include "type.h"
#include "libft_extend.h"
#include "store_tkns.h"

static void	store_quote(t_tkn *tkns, const char *src, size_t *i
	, size_t *t_i)
{
	char	c;

	c = src[*i];
	if (c == '\'')
		tkns[*t_i].type = SINGLE;
	else
		tkns[*t_i].type = DOUBLE;
	tkns[*t_i].head = (*i)++;
	while (src[*i] != c)
		(*i)++;
	tkns[(*t_i)++].tail = ++(*i);
	c = src[*i];
	if (ft_isspace(c))
		while (ft_isspace(src[*i]))
			(*i)++;
	else if (ft_istoken(c) || !c)
		return ;
	else
		store_word(tkns, src, i, t_i);
}

static void	store_normal_word(t_tkn *tkns, const char *src, size_t *i
	, size_t *t_i)
{
	char	c;

	tkns[*t_i].type = NORMAL;
	tkns[*t_i].head = *i;
	while (1)
	{
		c = src[++(*i)];
		if (ft_isspace(c))
		{
			tkns[(*t_i)++].tail = *i;
			while (ft_isspace(src[*i]))
				(*i)++;
			return ;
		}
		else if (ft_istoken(c) || !c)
			return ((void)(tkns[(*t_i)++].tail = *i));
		else if (c == '"' || c == '\'')
		{
			tkns[(*t_i)++].tail = *i;
			store_quote(tkns, src, i, t_i);
			return ;
		}
	}
}

void	store_word(t_tkn *tkns, const char *src, size_t *i, size_t *t_i)
{
	if (src[*i] == '"' || src[*i] == '\'')
		store_quote(tkns, src, i, t_i);
	else
		store_normal_word(tkns, src, i, t_i);
}
