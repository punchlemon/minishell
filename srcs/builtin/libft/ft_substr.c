/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:41:21 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/30 14:47:45 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	int		len_mall;
	size_t	i;

	if (len == 0 || (unsigned int)ft_strlen(s) <= start)
		return (ft_strdup("\0"));
	if (ft_strlen(s) - start < len)
	{
		len_mall = (int)ft_strlen(s) - (int)start + 1;
		ans = (char *)malloc(sizeof(char) * (len_mall + 1));
	}
	else
		ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		ans[i] = s[start + i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

// #include <stdio.h>

// int	main(void)r
// {
// 	char	*res;

// 	res = ft_substr("hnakayam", 3, 3);
// 	printf("%s\n", res);
// 	return (0);
// }
