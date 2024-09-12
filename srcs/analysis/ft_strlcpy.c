/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:35:46 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/12 16:56:13 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "string.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = -1;
	while (*(src + ++src_len))
		;
	if (dstsize == 0)
		return (src_len);
	if (dstsize > src_len + 1)
		dstsize = src_len + 1;
	*(char *)(dst + dstsize - 1) = 0;
	while (--dstsize)
		*(char *)(dst + dstsize - 1) = *(char *)(src + dstsize - 1);
	return (src_len);
}

size_t	ft_strlen(char *src)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	return (i);
}
