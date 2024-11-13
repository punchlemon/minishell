/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:15:44 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/30 14:36:27 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	ans;

	ans = 0;
	sign = 1;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		if (sign == 1 && (ans > LONG_MAX / 10
				|| ans * 10 > LONG_MAX - (*str - '0')))
			return ((int)LONG_MAX);
		if (sign == -1 && (ans > LONG_MAX / 10
				|| ans * 10 - 1 > LONG_MAX - *str + '0'))
			return ((int)LONG_MIN);
		ans = ans * 10 + *str - '0';
		str++;
	}
	return ((int)ans * sign);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	*num_str = " \t\v\n\f\r+2147483647";
// 	printf("%d\n", ft_atoi(num_str));
// 	printf("%d\n", atoi(num_str));
// 	return (0);
// }
