/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_lex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:56:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/14 02:11:50 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "lexer.h"
#include "ft_printf.h"
#include "libft.h"
#include "libft_extend.h"

static int	store_space(t_lex_data *lex_data, const char *src, size_t *i
	, size_t *lex_data_i)
{
	while (ft_isspace(src[*i]))
		(*i)++;
	lex_data[*lex_data_i].token = SPACE;
	(*lex_data_i)++;
	if (!src[*i])
		return (0);
	return (1);
}

static int	store_quote(t_lex_data *lex_data, const char *src, size_t *i
	, size_t *lex_data_i)
{
	char	c;

	c = src[*i];
	lex_data[*lex_data_i].head = ++(*i);
	while (src[*i] != c)
		(*i)++;
	if (c == '\'')
		lex_data[*lex_data_i].token = SINGLE;
	else
		lex_data[*lex_data_i].token = DOUBLE;
	lex_data[(*lex_data_i)++].tail = *i - 1;
	(*i)++;
	return (src[*i] && !ft_istoken(src[*i]) && !ft_isspace(src[*i]));
}

static void	store_word(t_lex_data *lex_data, const char *src, size_t *i
	, size_t *lex_data_i)
{
	char	c;
	size_t	head;

	head = *i;
	while (1)
	{
		c = src[*i];
		if (ft_istoken(c) || ft_isspace(c) || !c)
		{
			lex_data[*lex_data_i].token = NORMAL;
			lex_data[*lex_data_i].head = head;
			lex_data[(*lex_data_i)++].tail = *i - 1;
			return ;
		}
		if (c == '"' || c == '\'')
		{
			lex_data[*lex_data_i].token = NORMAL;
			lex_data[*lex_data_i].head = head;
			lex_data[(*lex_data_i)++].tail = *i - 1;
			if (!store_quote(lex_data, src, i, lex_data_i))
				return ;
			head = *i;
		}
		(*i)++;
	}
}

static void	store_token(t_lex_data *lex_data,  const char *src, size_t *i
	, size_t *lex_data_i)
{
	char	c;

	c = src[(*i)++];
	if (c == '(')
		lex_data[*lex_data_i].token = LPAREN;
	else if (c == ')')
		lex_data[*lex_data_i].token = RPAREN;
	else if (c == src[*i] && (*i)++)
	{
		if (c == '&')
			lex_data[*lex_data_i].token = AND_IF;
		else if (c == '|')
			lex_data[*lex_data_i].token = OR_IF;
		else if (c == '<')
			lex_data[*lex_data_i].token = DLESS;
		else if (c == '>')
			lex_data[*lex_data_i].token = DGREAT;
	}
	else if (c == '|')
		lex_data[*lex_data_i].token = PIPE;
	else if (c == '<')
		lex_data[*lex_data_i].token = LESS;
	else if (c == '>')
		lex_data[*lex_data_i].token = GREAT;
	(*lex_data_i)++;
}

void	store_lex(const char *src, t_lex_data *lex_data)
{
	size_t	i;
	size_t	lex_data_i;

	i = 0;
	while (ft_isspace(src[i]))
		i++;
	lex_data_i = 0;
	while (src[i])
	{
		if (ft_istoken(src[i]))
			store_token(lex_data, src, &i, &lex_data_i);
		else
			store_word(lex_data, src, &i, &lex_data_i);
		if (!src[i])
			break ;
		if (!store_space(lex_data, src, &i, &lex_data_i))
			return ;
	}
	lex_data[lex_data_i].token = END;
}
