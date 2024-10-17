/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:02:49 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 22:58:10 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extend.h"
#include "count_lex.h"

size_t	count_lex(const char *src)
{
	size_t		i;
	size_t		len;

	len = 0;
	i = 0;
	while (ft_isspace(src[i]))
		i++;
	while (src[i])
	{
		if (ft_istoken(src[i]))
		{
			if (!count_token(src, &i, &len))
				return (0);
		}
		else
		{
			if (!count_word(src, &i, &len))
				return (0);
		}
		if (!src[i])
			break ;
	}
	return (len);
}
