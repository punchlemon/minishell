/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:43:57 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/10 14:35:31 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*nobu_strjoin(char const *s1, char const *s2, ssize_t n)
{
	int		total_len;
	char	*ans;
	char	*put;
	ssize_t	i;

	total_len = (int)ft_strlen(s1) + n + 1;
	put = (char *)malloc(sizeof(char) * total_len);
	if (put == NULL)
		return (NULL);
	ans = put;
	i = 0;
	while (*s1)
		*put++ = *s1++;
	while (i < n)
	{
		*put++ = *s2++;
		i++;
	}
	*put = '\0';
	return (ans);
}

ssize_t	nobu_strchar(const char *s, char c)
{
	ssize_t	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
	{
		if (s[len] == c)
		{
			len++;
			return (len);
		}
		len++;
	}
	return (len);
}

// size_t	ft_strlen(const char *str)
// {
// 	size_t	len;

// 	len = 0;
// 	while (str[len])
// 		len++;
// 	return (len);
// }

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
