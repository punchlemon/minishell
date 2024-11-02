/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tkn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:25:58 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/02 21:30:01 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_tkns.h"

int	count_tkn(const char *src, size_t *len)
{
	char	c;
	size_t	i;

	i = 0;
	c = src[i];
	if (c == '(' || c == ')')
		;
	else
	{
		if (c == src[i + 1])
			i++;
		else
		{
			if (c == '&')
				return (0);
		}
	}
	i++;
	(*len)++;
	while (ft_isspace(src[i]))
		i++;
	return (i);
}
