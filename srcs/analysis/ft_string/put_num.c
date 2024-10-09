/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:46:07 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/06 19:37:30 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#define INT_BUF_LEN 11
#define INT_MIN_STR "-2147483648"
# define SIZE_T_BUF_LEN 20

int	put_num(int num)
{
	char	buffer[INT_BUF_LEN];
	char	*ptr;
	int		is_negative;

	if (num == INT_MIN)
		return (write(1, INT_MIN_STR, INT_BUF_LEN));
	ptr = buffer + INT_BUF_LEN;
	is_negative = num < 0;
	if (is_negative)
		num = -num;
	while (1)
	{
		*(--ptr) = '0' + (num % 10);
		num /= 10;
		if (num == 0)
			break ;
	}
	if (is_negative)
		*(--ptr) = '-';
	return (write(1, ptr, buffer + INT_BUF_LEN - ptr));
}

int	put_size_t(size_t num)
{
	char	buffer[SIZE_T_BUF_LEN];
	char	*ptr;

	ptr = buffer + SIZE_T_BUF_LEN;
	while (1)
	{
		*(--ptr) = '0' + (num % 10);
		num /= 10;
		if (num == 0)
			break ;
	}
	return (write(1, ptr, buffer + SIZE_T_BUF_LEN - ptr));
}
