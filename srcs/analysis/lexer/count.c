/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:02:49 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/06 14:57:11 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static size_t	count_tkn(const char *src)
{
	char	c;

	c = src[0];
	if (c == src[1])
		return (2);
	else if (c == '&')
		return (0);
	return (1);
}

static size_t	count_quote(const char *src)
{
	size_t	i;
	char	c;

	i = 0;
	c = src[i];
	i++;
	while (src[i] != c)
	{
		if (!src[i])
			return (0);
		i++;
	}
	i++;
	return (i);
}

static size_t	count_normal(const char *src)
{
	size_t	i;

	i = 0;
	while (ft_isnormal(src[i]))
		i++;
	return (i);
}

size_t	count_t_len(const char *src)
{
	size_t	i;
	size_t	t_len;
	size_t	tmp;

	t_len = 0;
	i = 0;
	while (src[i])
	{
		if (ft_istoken(src[i]))
			tmp = count_tkn(&src[i]);
		else if (ft_isquote(src[i]))
			tmp = count_quote(&src[i]);
		else
			tmp = count_normal(&src[i]);
		if (!tmp)
			return (0);
		i += tmp;
		t_len++;
		while (ft_isspace(src[i]))
			i++;
	}
	return (t_len);
}
