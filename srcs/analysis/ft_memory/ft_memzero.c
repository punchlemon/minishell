/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:46:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/23 19:46:48 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_memzero(char *dst, size_t n)
{
	while (n--)
		dst[n] = 0;
}

// void	mem_zero(void *dst, size_t bytes)
// {
// 	size_t	n64;
//
// 	if (!dst || !bytes)
// 		return ;
// 	n64 = bytes >> 3;
// 	while (n64--)
// 	{
// 		*(uint64_t *)dst = 0;
// 		dst += 8;
// 	}
// 	if (bytes & 0b100)
// 	{
// 		*(uint32_t *)dst = 0;
// 		dst += 4;
// 	}
// 	if (bytes & 0b10)
// 	{
// 		*(uint16_t *)dst = 0;
// 		dst += 2;
// 	}
// 	if (bytes & 0b1)
// 		*(uint8_t *)dst = 0;
// }
