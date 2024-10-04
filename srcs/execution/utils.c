/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 22:20:24 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/04 22:20:25 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_string.h"

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

char	*ft_strjoin(char *s1, char *s2)
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
