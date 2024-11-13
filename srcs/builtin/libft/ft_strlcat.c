/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:13:42 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/27 20:13:10 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	i;

	if (dest == NULL && dstsize == 0)
		return (ft_strlen(src) + dstsize);
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	i = 0;
	if (len_dest >= dstsize)
		return (len_src + dstsize);
	while (len_dest + i < dstsize - 1 && src[i])
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_src + len_dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	int			x = 10;
// 	const char		*sr = "Nakayam";
// 	char		dt[20] = "Hayanobu";
// 	const char	*sr2 = "Nakayam";
// 	char		dt2[20] = "Hayanobu";
// 	printf("ft = %lu\n", ft_strlcat(NULL, sr, 0));
// 	printf("lb = %lu\n", strlcat(NULL, sr2, 0));
// 	printf("lb = %lu\n", strlcat(dt2, sr2, 0));
// 	return (0);
// }
