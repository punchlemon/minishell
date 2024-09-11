/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_bytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:46:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/11 17:46:37 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

void	copy_bytes(void *dst, void *src, size_t bytes)
{
	size_t	n64;

	n64 = bytes >> 3;
	while (n64--)
	{
		*(uint64_t *)dst = *(uint64_t *)src;
		dst += 8;
		src += 8;
	}
	if (bytes & 0b100)
	{
		*(uint32_t *)dst = *(uint32_t *)src;
		dst += 4;
		src += 4;
	}
	if (bytes & 0b10)
	{
		*(uint16_t *)dst = *(uint16_t *)src;
		dst += 2;
		src += 2;
	}
	if (bytes & 0b1)
		*(uint8_t *)dst = *(uint8_t *)src;
}
