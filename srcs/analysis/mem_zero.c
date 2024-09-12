/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:46:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/12 16:41:23 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

void	mem_zero(void *dst, size_t bytes)
{
	size_t	n64;

	n64 = bytes >> 3;
	while (n64--)
	{
		*(uint64_t *)dst = 0;
		dst += 8;
	}
	if (bytes & 0b100)
	{
		*(uint32_t *)dst = 0;
		dst += 4;
	}
	if (bytes & 0b10)
	{
		*(uint16_t *)dst = 0;
		dst += 2;
	}
	if (bytes & 0b1)
		*(uint8_t *)dst = 0;
}
