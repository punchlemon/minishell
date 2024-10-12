/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:18:02 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/12 13:18:09 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putarg_check(char format, va_list *args, int *count)
{
	if (format == '%')
		ft_putchar_check('%', count);
	if (format == 'c')
		ft_putchar_check((char)va_arg(*args, int), count);
	if (format == 's')
		ft_putstr_check((char *)va_arg(*args, char *), count);
	if (format == 'p')
		ft_putptr_check((unsigned long long)va_arg(*args, void *), count);
	if (format == 'o')
		ft_putoct_check(va_arg(*args, int), count);
	if (format == 'u' || format == 'd' || format == 'i')
		ft_putdec_check(va_arg(*args, int), format, count);
	if (format == 'x' || format == 'X')
		ft_puthex_check(va_arg(*args, int), format, count);
	return (*count);
}

int	ft_printf(const char *source, ...)
{
	va_list	args;
	int		count;
	size_t	i;

	va_start(args, source);
	i = 0;
	count = 0;
	while (source[i])
	{
		if (source[i] == '%')
			ft_putarg_check(source[++i], &args, &count);
		else
			ft_putchar_check(source[i], &count);
		if (count == -1)
			break ;
		i++;
	}
	va_end(args);
	return (count);
}
