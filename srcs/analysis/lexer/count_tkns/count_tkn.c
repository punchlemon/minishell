/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tkn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:25:58 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/22 23:38:28 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_tkns.h"

int	count_tkn(const char *src, size_t *i, size_t *len)
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
	(*len)++;
	while (ft_isspace(src[*i]))
		(*i)++;
	return (1);
}
