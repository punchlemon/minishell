/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:23:05 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/14 16:23:04 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extend.h"
#include <stdlib.h>

int	count_word(const char *src, size_t *i, size_t *lex_data_len);

static void	count_space(const char *src, size_t *i, size_t *lex_data_len)
{
	while (ft_isspace(src[*i]))
		(*i)++;
	if (src[*i] && !ft_istoken(src[*i]))
		(*lex_data_len)++;
}

static int	count_quote(const char *src, size_t *i, size_t *lex_data_len)
{
	char	c;

	c = src[(*i)++];
	(*lex_data_len)++;
	while (src[*i] != c)
	{
		if (src[*i] == c)
			break ;
		if (!src[*i])
			return (0);
		(*i)++;
	}
	c = src[++(*i)];
	if (ft_isspace(c))
		return (count_space(src, i, lex_data_len), 1);
	else if (ft_istoken(c) || !c)
		return (1);
	else
		return (count_word(src, i, lex_data_len));
}

static int	count_normal_word(const char *src, size_t *i, size_t *lex_data_len)
{
	char	c;

	(*lex_data_len)++;
	while (1)
	{
		c = src[++(*i)];
		if (ft_isspace(c))
			return (count_space(src, i, lex_data_len), 1);
		else if (ft_istoken(c) || !c)
			return (1);
		else if (c == '"' || c == '\'')
			return (count_quote(src, i, lex_data_len));
	}
}

int	count_word(const char *src, size_t *i, size_t *lex_data_len)
{
	if (src[*i] == '"' || src[*i] == '\'')
		return (count_quote(src, i, lex_data_len));
	else
		return (count_normal_word(src, i, lex_data_len));
}
