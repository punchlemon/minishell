/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:12:57 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/27 20:18:30 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (src == NULL || dest == NULL)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char		*sr = "hnakayam";
// 	char		dt[1];
// 	const char	*sr2 = "hnakayam";
// 	char		dt2[1];
// 	printf("ft = %zu\n", ft_strlcpy(dt, sr, 0));
// 	printf("lb = %zu\n", strlcpy(dt2, sr2, 0));
// 	return (0);
// }
