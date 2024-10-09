/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:35:46 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 16:30:10 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len])
		len++;
	if (dstsize == 0)
		return (len);
	if (dstsize > len + 1)
		dstsize = len + 1;
	dst[dstsize - 1] = 0;
	i = 0;
	while (--dstsize)
	{
		dst[dstsize - 1] = src[dstsize - 1];
		i++;
	}
	return (len);
}
