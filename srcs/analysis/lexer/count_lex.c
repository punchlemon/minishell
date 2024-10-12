/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:02:49 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/12 13:50:01 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "ft_printf.h"
#include "libft.h"
#include "libft_extend.h"
#include <stdlib.h>

static void	count_space(const char *src, size_t *i, size_t *len)
{
	while (src[*i] && ft_isspace(src[*i]))
		(*i)++;
	(*len)++;
}

static int	count_quote(const char *src, size_t *i, size_t *len)
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
			return (0);
	}
	*len += 3;
	return (1);
}

static int	count_word(const char *src, size_t *i, size_t *len)
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
			if (!count_quote(src, i, len))
				return (0);
		}
		(*i)++;
	}
	*len += 3;
	return (1);
}

static int	count_token(const char *src, size_t *i, size_t *len)
{
	char	c;

	c = src[*i];
	if (c != '(' && c != ')' && c == src[*i + 1])
		(*i)++;
	else if (c == '&')
		return (0);
	(*len)++;
	return (1);
}

size_t	count_lex(const char *src)
{
	size_t	i;
	size_t	len;
	char	c;

	len = 0;
	i = 0;
	while (1)
	{
		count_space(src, &i, &len);
		c = src[i];
		if (!c)
			break ;
		if (!ft_istoken(c))
		{
			if (!count_word(src, &i, &len))
				return (0);
		}
		else
		{
			if (!count_token(src, &i, &len))
				return (0);
		}
		i++;
	}
	return (len);
}

//countする時点ではtokenのあとにtokenが来ても、すなわち&&||のような状態になっていたとしても成功とみなす
