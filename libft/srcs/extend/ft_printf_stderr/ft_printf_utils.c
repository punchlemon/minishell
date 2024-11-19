/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:52:07 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/19 15:59:14 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_stderr.h"

void	calc_digit(unsigned long num, int *count, int base)
{
	if (num == 0)
	{
		(*count)++;
		return ;
	}
	while (num != 0)
	{
		num /= base;
		(*count)++;
	}
	return ;
}

int	put_num(unsigned long long num, int digit, int base, char index)
{
	char	c;

	digit--;
	while (digit > 0)
	{
		num /= base;
		digit--;
	}
	if (num % base < 10)
	{
		c = num % base + '0';
		if (write(2, &c, 1) == -1)
			return (-1);
	}
	else
	{
		if (index == 'u')
			c = num % base - 10 + 'A';
		else if (index == 'l')
			c = num % base - 10 + 'a';
		if (write(2, &c, 1) == -1)
			return (-1);
	}
	return (0);
}
