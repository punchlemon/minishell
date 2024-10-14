/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:25:58 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/14 13:00:30 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extend.h"
#include <stdlib.h>

int	count_token(const char *src, size_t *i, size_t *lex_data_len)
{
	char		c;

	c = src[(*i)++];
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
	while (ft_isspace(src[*i]))
		(*i)++;
	return (1);
}
