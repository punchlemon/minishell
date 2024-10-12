/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_lex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:56:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/12 12:43:25 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include "libft_extend.h"
#include <stdlib.h>

static void	store_space(int *lex_data, const char *src, size_t *i, size_t *j)
{
	while (src[*i] && ft_isspace(src[*i]))
		(*i)++;
	lex_data[(*j)++] = SPACE;
}

static void	store_quote(const char *src, size_t *i, size_t *len)
{
	char	c;
	char	tmp;

	c = src[*i];
	while (1)
	{
		tmp = src[++(*i)];
		if (tmp == c)
			break ;
		if (!tmp)
			return ;
	}
	*len += 3;
}

static void	store_word(const char *src, size_t *i, size_t *len)
{
	char	c;

	while (1)
	{
		c = src[*i];
		if (ft_istoken(c) || ft_isspace(c) || c)
			break ;
		if (c == '"' || c == '\'')
		{
			*len += 3;
			store_quote(src, i, len);
		}
		(*i)++;
	}
	*len += 3;
}

static void	store_token(const char *src, size_t *i, size_t *len)
{
	char	c;

	c = src[*i];
	if (c != '(' && c != ')' && c == src[*i + 1])
		(*i)++;
	else if (c == '&')
	(*len)++;
}

void	store_lex(int *lex_data, const char *src)
{
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	j = 0;
	while (1)
	{
		store_space(lex_data, src, &i, &j);
		c = src[i];
		if (!c)
			break ;
		if (!ft_istoken(c))
			store_word(src, &i, &j);
		else
			store_token(src, &i, &j);
	}
}
