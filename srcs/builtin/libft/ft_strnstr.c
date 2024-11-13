/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:31:35 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/30 16:32:54 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*rest_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;
	size_t	n;

	i = 0;
	n = 0;
	while (haystack[i] && n < len)
	{
		j = 0;
		temp = i;
		while (haystack[temp] == needle[j] && temp < len)
		{
			if (j >= len)
				break ;
			j++;
			temp++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
		n++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	return (rest_strnstr(haystack, needle, len));
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*needle = "aka";
// 	char	*haystack = "hnakayam";
// 	int		len = 10;
// 	char	*ans = strnstr(haystack, needle, len);
// 	printf("ans = %p\n", ans);
// 	printf("letter : %c\n", *ans);
// 	printf("%s\n", ans);
// 	ans = ft_strnstr(haystack, needle, len);
// 	printf("ans = %p\n", ans);
// 	printf("letter : %c\n", *ans);
// 	printf("%s\n", ans);
// 	return (0);
// }
