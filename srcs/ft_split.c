/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:34:11 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/11 15:34:15 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_freemem(char ***p, size_t last_index)
{
	size_t	i;

	i = -1;
	while (++i < last_index)
	{
		free(*(char **)((*p) + i));
		*(char **)((*p) + i) = NULL;
	}
	free(*p);
	*p = NULL;
	return (NULL);
}

static int	ft_countword(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*ft_storeword(char const **s, char c)
{
	char	*temp;
	size_t	len;

	len = 0;
	while (**s != '\0' && **s != c)
	{
		len++;
		(*s)++;
	}
	temp = malloc((len + 1) * sizeof(char));
	if (temp != NULL)
		ft_strlcpy(temp, *s - len, len + 1);
	return (temp);
}

char	**ft_split(char const *s, char c)
{
	char	**buff;
	size_t	i;

	if (s == NULL)
		return (NULL);
	buff = malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (buff == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			buff[i] = ft_storeword(&s, c);
			if (buff[i] == NULL)
				return (ft_freemem(&buff, i));
			i++;
		}
	}
	*(char **)(buff + i) = NULL;
	return (buff);
}
