/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:31:43 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/30 16:25:37 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	search_end(char const *s1, char const *set)
{
	size_t	len_set;
	int		end;

	len_set = ft_strlen(s1);
	end = len_set - 1;
	while (end >= 0 && check(set, s1[end]))
		end--;
	return (end);
}

static int	search_start(char const *s1, char const *set)
{
	int		start;

	start = 0;
	while (check(set, s1[start]) && s1[start])
		start++;
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ans;
	int		start;
	int		end;
	int		i;

	start = search_start(s1, set);
	end = search_end(s1, set);
	if (end < 0)
	{
		ans = (char *)malloc(sizeof(char) * 1);
		ans[0] = '\0';
		return (ans);
	}
	ans = (char *)malloc(sizeof(char) * ((end - start + 1) + 1));
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		ans[i] = s1[start];
		i++;
		start++;
	}
	ans[i] = '\0';
	return (ans);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s1 = "1234AAA22331122";
// 	char	*set = "1234";
// 	printf("%s\n", ft_strtrim(s1, set));
// 	return (0);
// }
