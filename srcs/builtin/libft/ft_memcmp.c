/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:19:47 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/19 14:39:22 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str = "libft-test-tokyo\0\0\0acdfg\0\0\0\0\0";
// 	char	*cmp = "libft-test-tokyo\0\0\0acdfg\0\0\0\0\0";
// 	printf("%d\n", ft_memcmp(str, cmp, 2));
// 	return (0);
// }
