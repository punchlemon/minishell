/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:23:05 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/22 23:39:15 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_tkns.h"

static int	count_quote(const char *src, size_t *i, size_t *len)
{
	char	c;

	c = src[(*i)++];
	(*len)++;
	while (src[*i] != c)
	{
		if (src[*i] == c)
			break ;
		if (!src[*i])
			return (0);
		(*i)++;
	}
	++(*i);
	c = src[*i];
	if (ft_isspace(c))
	{
		while (ft_isspace(src[*i]))
			(*i)++;
		return (1);
	}
	else if (ft_istoken(c) || !c)
		return (1);
	else
		return (count_word(src, i, len));
}

static int	count_normal_word(const char *src, size_t *i, size_t *len)
{
	char	c;

	(*len)++;
	while (1)
	{
		c = src[++(*i)];
		if (ft_isspace(c))
		{
			while (ft_isspace(src[*i]))
				(*i)++;
			return (1);
		}
		else if (ft_istoken(c) || !c)
			return (1);
		else if (c == '"' || c == '\'')
			return (count_quote(src, i, len));
	}
}

int	count_word(const char *src, size_t *i, size_t *len)
{
	if (src[*i] == '"' || src[*i] == '\'')
		return (count_quote(src, i, len));
	else
		return (count_normal_word(src, i, len));
}
