/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str_and_or.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:39:38 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/04 22:16:51 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

int	move_quote(char *src, size_t *l)
{
	char	c;

	c = src[*l];
	while (src[++(*l)])
	{
		if (src[*l] == c)
			return (1);
	}
	return (0);
}

int	move_paren(char *src, size_t *l)
{
	char	c;

	while (src[*l])
	{
		c = src[*l];
		if (c == '"' || c == '\'')
		{
			if (!move_quote(src, l))
				return (0);
			continue ;
		}
		(*l)++;
		if (c == '(')
		{
			if (!move_paren(src, l))
				return (0);
		}
		else if (c == ')')
			return (1);
	}
	return (0);
}

int	check_and_or(t_str_slice *str_s, char *src, size_t *i, size_t *l)
{
	char	c;
	t_str	*str;
	size_t	n;

	c = src[*l];
	if ((!*i && !*l) || c != src[*l + 1])
		return (0);
	str = create_str_len(src, *l);
	if (!str || !append_str_slice_one_str(str_s, str))
		return (0);
	str = create_str_len(src + *l, 2);
	if (!str || !append_str_slice_one_str(str_s, str))
		return (0);
	n = 0;
	while (1)
	{
		c = src[*l + 2 + n];
		if (!c || c == '&' || c == '|')
			return (0);
		if (!ft_isspace(c))
			return (*i += (*l + 2 + n - 1), *l = 0, 1);
		n++;
	}
}

int	move_word(t_str_slice *str_s, char *src, size_t *i, size_t *l)
{
	char	c;

	c = src[*l];
	if (c == '"' || c == '\'')
	{
		if (!move_quote(src, l))
			return (0);
	}
	else if (c == '(')
	{
		(*l)++;
		if (!move_paren(src, l))
			return (0);
	}
	else if (c == '&' || c == '|')
	{
		if (!check_and_or(str_s, src, i, l))
			return (0);
	}
	else if (c == ')')
		return (0);
	(*l)++;
	return (1);
}
