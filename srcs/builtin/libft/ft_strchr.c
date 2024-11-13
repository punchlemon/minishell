/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:26:59 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/19 11:58:08 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*s = "hnakayam";
// 	char	c = '\0';
// 	char	*ans = strchr(s, c);
// 	printf("ans = %p\n", ans);
// 	printf("letter : %c\n", *ans);
// 	printf("%s\n", ans);
// 	ans = ft_strchr(s, c);
// 	printf("ans = %p\n", ans);
// 	printf("letter : %c\n", *ans);
// 	printf("%s\n", ans);
// 	return (0);
// }
