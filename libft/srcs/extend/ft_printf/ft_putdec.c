/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:20:07 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/12 13:20:01 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdec_check(int n, char format, int *count)
{
	unsigned long long	u_n;

	if (n < 0 && format != 'u')
	{
		if ((long long)n == -2147483648)
		{
			ft_putstr_check("-2147483648", count);
			return (*count);
		}
		ft_putchar_check('-', count);
		n = -n;
		if (*count == -1)
			return (*count);
	}
	u_n = (unsigned long long)n & 0xffffffff;
	return (ft_putnumber_check(u_n, format, count, 10));
}
