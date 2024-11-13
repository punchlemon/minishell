/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:32:42 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/19 05:32:58 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}
// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	res;
// 	int	c;

// 	c = 'Z';
// 	printf("c = %d\n", c);
// 	res = tolower(c);
// 	printf("res = %d\n", res);
// 	res = ft_tolower(c);
// 	printf("ft_res = %d\n", res);
// 	return (0);
// }
