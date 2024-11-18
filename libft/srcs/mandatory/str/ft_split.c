/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:34:11 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/18 14:22:37 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*nobu_strcpy(char *ans, char const *s, int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ans[i] = s[start + i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

static void	all_free(char **ans, int i)
{
	while (i > 0)
	{
		i--;
		free(ans[i]);
	}
	free(ans);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	flag;
	int	i;

	count = 0;
	flag = 0;
	i = 0;
	while (s[i])
	{
		if (flag == 0 && s[i] != c)
		{
			count++;
			flag = 1;
		}
		else if (flag == 1 && s[i] == c)
		{
			flag = 0;
		}
		i++;
	}
	return (count);
}

static char	**rest_of_split(char const *s, char c, char **ans, int count)
{
	int	i;
	int	start;
	int	len;

	start = 0;
	i = 0;
	while (i < count)
	{
		while (s[start] == c)
			start++;
		len = 0;
		while (s[start + len] != c && s[start + len])
			len++;
		ans[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (ans[i] == NULL)
		{
			all_free(ans, i);
			return (NULL);
		}
		nobu_strcpy(ans[i], s, start, len);
		i++;
		start += len;
	}
	ans[i] = NULL;
	return (ans);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		count;

	count = count_words(s, c);
	ans = (char **)malloc(sizeof(char *) * (count + 1));
	if (ans == NULL)
		return (NULL);
	return (rest_of_split(s, c, ans, count));
}
