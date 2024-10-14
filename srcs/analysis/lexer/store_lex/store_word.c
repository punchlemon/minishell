/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:22:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/14 19:58:11 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lex_data.h"
#include "libft_extend.h"

void	store_word(t_lex_data *lex_data, const char *src, size_t *i,
			size_t *lex_data_i);

static void	store_quote(t_lex_data *lex_data, const char *src, size_t *i
	, size_t *lex_data_i)
{
	char	c;

	c = src[(*i)++];
	if (c == '\'')
		lex_data[*lex_data_i].token = SINGLE;
	else
		lex_data[*lex_data_i].token = DOUBLE;
	lex_data[*lex_data_i].head = *i;
	while (src[*i] != c)
		(*i)++;
	lex_data[(*lex_data_i)++].tail = *i;
	c = src[++(*i)];
	if (ft_isspace(c))
		while (ft_isspace(src[*i]))
			(*i)++;
	else if (ft_istoken(c) || !c)
		return ;
	else
		store_word(lex_data, src, i, lex_data_i);
}

static void	store_normal_word(t_lex_data *lex_data, const char *src, size_t *i
	, size_t *lex_data_i)
{
	char	c;

	lex_data[*lex_data_i].token = NORMAL;
	lex_data[*lex_data_i].head = *i;
	while (1)
	{
		c = src[++(*i)];
		if (ft_isspace(c))
		{
			lex_data[(*lex_data_i)++].tail = *i;
			while (ft_isspace(src[*i]))
				(*i)++;
			return ;
		}
		else if (ft_istoken(c) || !c)
		{
			lex_data[(*lex_data_i)++].tail = *i;
			return ;
		}
		else if (c == '"' || c == '\'')
		{
			lex_data[(*lex_data_i)++].tail = *i;
			store_quote(lex_data, src, i, lex_data_i);
			return ;
		}
	}
}

void	store_word(t_lex_data *lex_data, const char *src, size_t *i
	, size_t *lex_data_i)
{
	if (src[*i] == '"' || src[*i] == '\'')
		store_quote(lex_data, src, i, lex_data_i);
	else
		store_normal_word(lex_data, src, i, lex_data_i);
}
