/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_put_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:50:13 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/19 15:58:59 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_stderr.h"

ssize_t	printf_d_i(int num, int **crr_len)
{
	int	digit;

	digit = 0;
	if (num == INT_MIN)
	{
		**crr_len += 11;
		return (write(2, "-2147483648", 11));
	}
	if (num < 0)
	{
		num *= -1;
		(**crr_len)++;
		if (write(2, "-", 1) == -1)
			return (-1);
	}
	calc_digit(num, &digit, 10);
	(**crr_len) += digit;
	while (digit > 0)
	{
		if (put_num(num, digit, 10, 'n') == -1)
			return (-1);
		digit--;
	}
	return (0);
}

ssize_t	printf_u(unsigned int num, int **crr_len)
{
	int	digit;

	digit = 0;
	calc_digit(num, &digit, 10);
	(**crr_len) += digit;
	while (digit > 0)
	{
		if (put_num(num, digit, 10, 'n') == -1)
			return (-1);
		digit--;
	}
	return (0);
}

ssize_t	printf_p(void *p, int **crr_len)
{
	unsigned long long	num;
	int					digit;

	digit = 0;
	num = (unsigned long long)p;
	calc_digit(num, &digit, 16);
	(**crr_len) += digit;
	while (digit > 0)
	{
		if (put_num(num, digit, 16, 'l') == -1)
			return (-1);
		digit--;
	}
	return (0);
}

ssize_t	printf_x(unsigned int num, int **crr_len)
{
	int	digit;

	digit = 0;
	calc_digit(num, &digit, 16);
	(**crr_len) += digit;
	while (digit > 0)
	{
		if (put_num(num, digit, 16, 'l') == -1)
			return (-1);
		digit--;
	}
	return (0);
}

ssize_t	printf_large_x(unsigned int num, int **crr_len)
{
	int	digit;

	digit = 0;
	calc_digit(num, &digit, 16);
	(**crr_len) += digit;
	while (digit > 0)
	{
		if (put_num(num, digit, 16, 'u') == -1)
			return (-1);
		digit--;
	}
	return (0);
}
