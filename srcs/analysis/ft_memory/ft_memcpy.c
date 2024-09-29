/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:18:23 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/23 19:47:38 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(char *dst, char *src, size_t n)
{
	size_t	i;

	if (src > dst)
	{
		i = 0;
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else if (src < dst)
		while (n--)
			dst[n] = src[n];
}

// void	fwd(void *dst, void *src, size_t n64, uint32_t bytes)
// {
// 	while (n64--)
// 	{
// 		*(uint64_t *)dst = *(uint64_t *)src;
// 		dst += 8;
// 		src += 8;
// 	}
// 	if (bytes & 0b100)
// 	{
// 		*(uint32_t *)dst = *(uint32_t *)src;
// 		dst += 4;
// 		src += 4;
// 	}
// 	if (bytes & 0b10)
// 	{
// 		*(uint16_t *)dst = *(uint16_t *)src;
// 		dst += 2;
// 		src += 2;
// 	}
// 	if (bytes & 0b1)
// 		*(uint8_t *)dst = *(uint8_t *)src;
// }
//
// void	rev(void *dst, void *src, size_t n64, uint32_t bytes)
// {
// 	while (n64--)
// 	{
// 		dst -= 8;
// 		src -= 8;
// 		*(uint64_t *)dst = *(uint64_t *)src;
// 	}
// 	if (bytes & 0b100)
// 	{
// 		dst -= 4;
// 		src -= 4;
// 		*(uint32_t *)dst = *(uint32_t *)src;
// 	}
// 	if (bytes & 0b10)
// 	{
// 		dst -= 2;
// 		src -= 2;
// 		*(uint16_t *)dst = *(uint16_t *)src;
// 	}
// 	if (bytes & 0b1)
// 	{
// 		dst -= 1;
// 		src -= 1;
// 		*(uint8_t *)dst = *(uint8_t *)src;
// 	}
// }
//
// void	copy_bytes(void *dst, void *src, size_t bytes)
// {
// 	if (dst == src || !bytes)
// 		return ;
// 	if (dst < src)
// 		fwd(dst, src, bytes >> 3, bytes & 0b100);
// 	else
// 		rev(dst + bytes, src + bytes, bytes >> 3, bytes & 0b100);
// }
