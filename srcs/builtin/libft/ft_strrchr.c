/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:01:27 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/27 20:18:54 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)&s[len]);
	while (len > 0)
	{
		len--;
		if (s[len] == (unsigned char)c)
			return ((char *)&s[len]);
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*s = "libft-test-tokyo";
// 	char	c = 'l' + 256;
// 	char	*ans = strrchr(s, c);
// 	printf("ans = %p\n", ans);
// 	printf("letter : %c\n", *ans);
// 	printf("%s\n", ans);
// 	// ans = ft_strrchr(s, c);
// 	// printf("ans = %p\n", ans);
// 	// printf("letter : %c\n", *ans);
// 	// printf("%s\n", ans);
// 	return (0);
// }
