/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:30:02 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/19 14:16:55 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n - 1 && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	const char	*s1 = "hnakayam\200";
// 	const char	*s2 = "hnakayam\0";
// 	int			n = 10;
// 	printf("ft = %d\n", ft_strncmp(s1, s2, n));
// 	printf("lb = %d\n", strncmp(s1, s2, n));
// 	return (0);	
// }
