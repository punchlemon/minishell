/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:09:01 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/12 13:19:45 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_check(char s, int *count)
{
	if (ft_putchar(s) == -1)
		*count = -1;
	else
		(*count)++;
	return (*count);
}

int	ft_putstr_check(char *s, int *count)
{
	int	len;

	len = ft_putstr(s);
	if (len == -1)
		*count = len;
	else
		*count += len;
	return (*count);
}

int	ft_putnum_check(char n, char format, int *count)
{
	if (n < 10)
		n += '0';
	else if (n < 16 && format == 'X')
		n += ('A' - 10);
	else if (n < 16)
		n += ('a' - 10);
	else
		n = 0;
	ft_putchar_check(n, count);
	return (*count);
}
