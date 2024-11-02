/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:02:49 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/02 23:23:01 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lexer.h"

static int	count_tkn(const char *src)
{
	char	c;

	c = src[0];
	if (c == '(' || c == ')')
		;
	else if (c == src[1])
		return (2);
	else if (c == '&')
		return (0);
	return (1);
}

static int	count_quote(const char *src)
{
	size_t	i;
	char	c;

	i = 0;
	c = src[i];
	i++;
	while (src[i] != c)
		i++;
	i++;
	return (i);
}

static int	count_normal_word(const char *src)
{
	size_t	i;

	i = 0;
	while (ft_isnormal_word(src[i]))
		i++;
	return i;
}

size_t	count_tkns(const char *src)
{
	size_t	i;
	size_t	t_len;
	size_t	tmp;

	t_len = 0;
	i = 0;
	while (ft_isspace(src[i]))
		i++;
	while (src[i])
	{
		if (ft_istoken(src[i]))
			tmp = count_tkn(&src[i]);
		else if (ft_isquote(src[i]))
			tmp = count_quote(&src[i]);
		else
			tmp = count_normal_word(&src[i]);
		if (!tmp)
			return (0);
		i += tmp;
		t_len++;
		while (ft_isspace(src[i]))
			i++;
	}
	return (t_len);
}
