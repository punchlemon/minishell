/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tkns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:02:49 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/02 22:02:21 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_tkns.h"

size_t	count_tkns(const char *src)
{
	size_t	i;
	size_t	tmp;
	size_t	len;

	len = 0;
	i = 0;
	while (ft_isspace(src[i]))
		i++;
	while (src[i])
	{
		if (ft_istoken(src[i]))
		{
			tmp = count_tkn(&src[i], &len);
			if (!tmp)
				return (0);
			i += tmp;
		}
		else
		{
			if (!count_word_len(src, &i, &len))
				return (0);
		}
		while (ft_isspace(src[i]))
			i++;
	}
	return (len);
}
