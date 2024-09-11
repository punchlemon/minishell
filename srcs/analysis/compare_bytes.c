/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_bytes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:47:14 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/11 17:48:06 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

uint16_t	reverse16(uint16_t value)
{
	return ((value >> 8) | (value << 8));
}

uint32_t	reverse32(uint32_t value)
{
	return ((value >> 24)
		| ((value >> 8) & 0x0000FF00)
		| ((value << 8) & 0x00FF0000)
		| (value << 24));
}

uint64_t	reverse64(uint64_t value)
{
	return ((value >> 56)
		| ((value >> 40) & 0x000000000000FF00)
		| ((value >> 24) & 0x0000000000FF0000)
		| ((value >> 8) & 0x00000000FF000000)
		| ((value << 8) & 0x000000FF00000000)
		| ((value << 24) & 0x0000FF0000000000)
		| ((value << 40) & 0x00FF000000000000)
		| (value << 56));
}

int	compare_below_8bytes(void *a, void *b, size_t bytes)
{
	int		res;
	int32_t	tmp32;
	int16_t	tmp16;

	if (bytes & 0b100)
	{
		tmp32 = reverse32(*(uint32_t *)a) - reverse32(*(uint32_t *)b);
		res = (tmp32 > 0) - (tmp32 < 0);
		if (res)
			return (res);
		a += 4;
		b += 4;
	}
	if (bytes & 0b10)
	{
		tmp16 = reverse16(*(uint16_t *)a) - reverse16(*(uint16_t *)b);
		res = (tmp16 > 0) - (tmp16 < 0);
		if (res)
			return (res);
		a += 2;
		b += 2;
	}
	return ((bytes & 0b1)
		* (*(uint8_t *)a > *(uint8_t *)b) - (*(uint8_t *)a < *(uint8_t *)b));
}

int	compare_bytes(void *a, void *b, size_t bytes)
{
	int		res;
	size_t	n64;
	int64_t	tmp64;

	n64 = bytes >> 3;
	while (n64--)
	{
		tmp64 = reverse64(*(uint64_t *)a) - reverse64(*(uint64_t *)b);
		res = (tmp64 > 0) - (tmp64 < 0);
		if (res)
			return (res);
		a += 8;
		b += 8;
	}
	return (compare_below_8bytes(a, b, bytes));
}
