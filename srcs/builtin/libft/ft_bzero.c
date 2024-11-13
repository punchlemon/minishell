/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:16:40 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/19 05:33:46 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ss;

	ss = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ss[i] = 0;
		i++;
	}
	return ;
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	unsigned char	str[10];
// 	int		size = 10;
// 	int	i = 0;
// 	// bzero(str, size);
// 	// while (i < 10)
// 	// {
// 	// 	printf("%d\n", str[i]);
// 	// 	i++;
// 	// }
// 	ft_bzero(str, size);
// 	i = 0;
// 	while (i < 10)
// 	{
// 		printf("%d\n", str[i]);
// 		i++;
// 	}
// 	return (0);
// }
