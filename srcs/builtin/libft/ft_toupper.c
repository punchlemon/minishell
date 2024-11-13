/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:33:14 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/19 05:33:15 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	res;
// 	int	c;

// 	c = 'z';
// 	printf("c = %d\n", c);
// 	res = toupper(c);
// 	printf("res = %d\n", res);
// 	res = ft_toupper(c);
// 	printf("ft_res = %d\n", res);
// 	return (0);
// }
