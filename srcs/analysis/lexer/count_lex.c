/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:02:49 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/14 02:09:09 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include "libft_extend.h"
#include "ft_printf.h"

int	count_space(const char *src, size_t *i, size_t *lex_data_len)
{
	while (ft_isspace(src[*i]))
		(*i)++;
	(*lex_data_len)++;
	if (!src[*i])
		return (0);
	return (1);
}

static int	count_quote(const char *src, size_t *i, size_t *lex_data_len)
{
	char	c;

	c = src[*i];
	while (1)
	{
		(*i)++;
		if (src[*i] == c)
		{
			(*lex_data_len)++;
			(*i)++;
			return (1);
		}
		else if (!src[*i])
			return (0);
	}
}

static int	count_word(const char *src, size_t *i, size_t *lex_data_len)
{
	char	c;

	while (1)
	{
		c = src[*i];
		if (ft_istoken(c) || ft_isspace(c) || !c)
			return ((*lex_data_len)++, 1);
		if (c == '"' || c == '\'')
		{
			ft_printf("%d\n", (int)*i);
			(*lex_data_len)++;
			if (!count_quote(src, i, lex_data_len))
				return (0);
			if (!src[*i] || ft_istoken(src[*i]) || ft_isspace(src[*i]))
				return (1);
			(*i)--;
		}
		(*i)++;
	}
}

static int	count_token(const char *src, size_t *i, size_t *lex_data_len)
{
	char		c;

	c = src[*i];
	(*i)++;
	if (c != '(' && c != ')')
	{
		if (c == src[*i])
			(*i)++;
		else
		{
			if (c == '&')
				return (0);
		}
	}
	(*lex_data_len)++;
	return (1);
}

size_t	count_lex(const char *src)
{
	size_t		i;
	size_t		lex_data_len;

	lex_data_len = 0;
	i = 0;
	while (ft_isspace(src[i]))
		i++;
	while (src[i])
	{
		if (ft_istoken(src[i]))
		{
			if (!count_token(src, &i, &lex_data_len))
				return (0);
		}
		else
		{
			if (!count_word(src, &i, &lex_data_len))
				return (0);
		}
		if (!src[i])
			break ;
		if (!count_space(src, &i, &lex_data_len))
			return (lex_data_len);
	}
	return (lex_data_len);
}
