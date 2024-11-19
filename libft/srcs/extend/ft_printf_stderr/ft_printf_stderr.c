/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:52:15 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/19 15:58:07 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_stderr.h"

int	nobu_putstr(char **crr, int *crr_len)
{
	int	len;

	len = 0;
	while (*(*crr + len) != '%' && *(*crr + len))
		len++;
	if (write(2, *crr, len) == -1)
		return (-1);
	*crr_len += len;
	*crr += len;
	return (0);
}

ssize_t	nobu_format(char **crr, int *crr_len, va_list *ap)
{
	(*crr)++;
	if (*((*crr)) == '\0')
		return (-2);
	if (**crr == 'c')
		return (printf_c(va_arg(*ap, int), &crr_len));
	else if (**crr == 's')
		return (printf_s(va_arg(*ap, char *), &crr_len));
	else if (**crr == 'p')
	{
		if (write(2, "0x", 2) == -1)
			return (-1);
		*crr_len += 2;
		return (printf_p(va_arg(*ap, void *), &crr_len));
	}
	else if (**crr == 'd' || **crr == 'i')
		return (printf_d_i(va_arg(*ap, int), &crr_len));
	else if (**crr == 'u')
		return (printf_u(va_arg(*ap, unsigned int), &crr_len));
	else if (**crr == 'x')
		return (printf_x(va_arg(*ap, unsigned int), &crr_len));
	else if (**crr == 'X')
		return (printf_large_x(va_arg(*ap, unsigned int), &crr_len));
	else if (**crr == '%')
		return (printf_percent(&crr_len));
	return (*crr_len);
}

int	ft_printf_stderr(const char *fmt, ...)
{
	va_list	ap;
	int		ans;
	char	*crr;

	va_start(ap, fmt);
	crr = (char *)fmt;
	ans = 0;
	while (*crr != '\0')
	{
		if (*crr != '%' && *crr)
		{
			if (nobu_putstr(&crr, &ans) == -1)
				return (-1);
		}
		else if (*crr == '%')
		{
			if (nobu_format(&crr, &ans, &ap) == -1)
				return (-1);
			if (*crr == '\0')
				return (ans);
			crr++;
		}
	}
	va_end(ap);
	return (ans);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("\nres = %d\n", ft_printf("%c", 'a'));
// 	printf("\nres = %d\n", printf("%c", 'a'));
// 	printf("\nres = %d\n", ft_printf("%s", "hnakayam"));
// 	printf("\nres = %d\n", printf("%s", "hnakayam"));
// 	printf("\nres = %d\n", ft_printf("%d", INT_MAX));
// 	printf("\nres = %d\n", printf("%d", INT_MAX));
// 	printf("\nres = %d\n", ft_printf("%d", INT_MIN));
// 	printf("\nres = %d\n", printf("%d", INT_MIN));
// 	printf("\nres = %d\n", ft_printf("%d", 0));
// 	printf("\nres = %d\n", printf("%d", 0));
// 	printf("\nres = %d\n", ft_printf("%i", INT_MAX));
// 	printf("\nres = %d\n", printf("%i", INT_MAX));
// 	printf("\nres = %d\n", ft_printf("%i", INT_MIN));
// 	printf("\nres = %d\n", printf("%i", INT_MIN));
// 	printf("\nres = %d\n", ft_printf("%i", 0));
// 	printf("\nres = %d\n", printf("%i", 0));
// 	printf("\nres = %d\n", ft_printf("%u", UINT_MAX));
// 	printf("\nres = %d\n", printf("%u", UINT_MAX));
// 	printf("\nres = %d\n", ft_printf("%u", 0));
// 	printf("\nres = %d\n", printf("%u", 0));
// 	printf("\nres = %d\n", ft_printf("%p", "hnakayam"));
// 	printf("\nres = %d\n", printf("%p", "hnakayam"));
// 	printf("\nres = %d\n", ft_printf("%p", NULL));
// 	printf("\nres = %d\n", printf("%p", NULL));
// 	printf("\nres = %d\n", ft_printf("%x", ULONG_MAX));
// 	printf("\nres = %d\n", printf("%x", ULONG_MAX));
// 	printf("\nres = %d\n", ft_printf("%x", 0));
// 	printf("\nres = %d\n", printf("%x", 0));
// 	printf("\nres = %d\n", ft_printf("%X", ULONG_MAX));
// 	printf("\nres = %d\n", printf("%X", ULONG_MAX));
// 	printf("\nres = %d\n", ft_printf("%X", 0));
// 	printf("\nres = %d\n", printf("%X", 0));
// 	printf("\nres = %d\n", ft_printf("%%"));
// 	printf("\nres = %d\n", printf("%%"));
// 	printf("\nres = %d\n", ft_printf("no_format: %"));
// 	printf("\nres = %d\n", printf("no_format: %"));
// }
