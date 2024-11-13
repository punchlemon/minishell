/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:27:16 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/19 05:28:44 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*ans;

	len = ft_strlen(s1);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ans[i] = s1[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*s1 = "hnakayam";
// 	char	*res = ft_strdup(s1);
// 	printf("%s\n", res);
// 	res = strdup(s1);
// 	printf("%s\n", res);
// 	return (0);
// }
