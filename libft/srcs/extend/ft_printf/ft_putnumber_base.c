/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:59:58 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/12 13:20:31 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_digit(unsigned long long n, int *digit, int base)
{
	*digit = 1;
	while (n >= (unsigned int)base)
	{
		n /= base;
		(*digit)++;
	}
}

char	get_place_num(unsigned long long n, int digit, int base)
{
	while (digit--)
		n /= base;
	n %= base;
	return (n & 0x0f);
}

void	remove_place_num(unsigned long long *n, int digit, int base)
{
	int					i;
	unsigned long long	minus;

	if (digit == 1)
		*n = 0;
	else
	{
		i = 1;
		minus = base;
		while (i < (digit - 1))
		{
			minus *= base;
			i++;
		}
		minus *= get_place_num(*n, digit - 1, base);
		*n -= minus;
	}
}

int	ft_putnumber_check(unsigned long long n, char fmt, int *count, int base)
{
	int	digit;

	get_digit(n, &digit, base);
	while (digit)
	{
		ft_putnum_check(get_place_num(n, digit - 1, base), fmt, count);
		if (*count == -1)
			return (*count);
		remove_place_num(&n, digit, base);
		digit--;
	}
	return (*count);
}
