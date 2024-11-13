/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:15:19 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/19 05:28:50 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*ans;
	int		i;

	total_len = (int)ft_strlen(s1) + (int)ft_strlen(s2) + 1;
	ans = (char *)malloc(sizeof(char) * total_len);
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		ans[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		ans[i] = *s2;
		s2++;
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", ft_strjoin("koji ", "motoyama"));
// 	return (0);
// }
