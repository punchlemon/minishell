/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_lex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:56:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/12 14:26:39 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "ft_printf.h"
#include "libft.h"
#include "libft_extend.h"
#include <stdlib.h>

static void	store_space(size_t *lex_data, const char *src, size_t *i, size_t *j)
{
	while (src[*i] && ft_isspace(src[*i]))
		(*i)++;
	lex_data[(*j)++] = SPACE;
}

static void	store_quote(size_t *lex_data, const char *src, size_t *i, size_t *j)
{
	size_t	head;
	char	c;

	c = src[*i];
	head = ++(*i);
	while (src[*i] != c)
		(*i)++;
	if (c == '\'')
		lex_data[(*j)++] = SINGLE;
	else
		lex_data[(*j)++] = DOUBLE;
	lex_data[(*j)++] = head;
	lex_data[(*j)++] = *i - 1;
	(*i)++;
}

static void	store_word(size_t *lex_data, const char *src, size_t *i, size_t *j)
{
	char	c;
	size_t	head;

	head = *i;
	while (1)
	{
		c = src[*i];
		if (ft_istoken(c) || ft_isspace(c) || c)
			break ;
		if (c == '"' || c == '\'')
		{
			lex_data[(*j)++] = NORMAL;
			lex_data[(*j)++] = head;
			lex_data[(*j)++] = *i - 1;
			store_quote(lex_data, src, i, j);
		}
		(*i)++;
	}
	lex_data[(*j)++] = NORMAL;
	lex_data[(*j)++] = head;
	lex_data[(*j)++] = *i - 1;
}

static void	store_token(size_t *lex_data,  const char *src, size_t *i, size_t *j)
{
	char	c;

	c = src[*i];
	(void)lex_data;
	(void)j;
	// if (c != '(' && c != ')' && c == src[*i + 1])
	// 	(*i)++;
	// else if (c == '&')
	// (*len)++;
}

void	store_lex(size_t *lex_data, const char *src)
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
			store_word(lex_data, src, &i, &j);
		else
			store_token(lex_data, src, &i, &j);
	}
}
