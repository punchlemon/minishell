/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_delete_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:34:18 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/11 19:24:10 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_string.h"

size_t	ft_strlen(char *src)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	return (i);
}

int	update_cap(size_t len, size_t *cap)
{
	if (!cap)
		return (-1);
	if (*cap >= len)
		return (0);
	if (*cap == 0)
		*cap = 1;
	while (1)
	{
		if (*cap >= len)
			return (1);
		if (*cap < 1024)
			*cap *= 2;
		else
			*cap *= 1.25;
	}
}

void	*delete_string(t_string *str)
{
	if (str && str->p)
		free(str->p);
	free(str);
}

t_string	*create_string(char *src)
{
	t_string	*str;

	str = malloc(sizeof(t_string));
	if (!str)
		return (NULL);
	str->len = 0;
	str->cap = 0;
	str->p = NULL;
	if (!src)
		return (str->p = NULL, str);
	str->len = ft_strlen(src);
	if (update_cap(str->len, &str->cap) == -1)
		return (delete_string(str));
	if (str->cap == 0)
		return (str);
	str->p = malloc(sizeof(char) * str->cap);
	if (!str->p)
		return (delete_string(str));
	copy_bytes(str->p, src, str->len);
}

t_string	*create_string_len(size_t len)
{
	t_string	*str;

	str = malloc(sizeof(t_string));
	if (!str)
		return (NULL);
	str->len = len;
	str->cap = 0;
	str->p = NULL;
	if (update_cap(str->len, &str->cap) == -1)
		return (delete_string(str));
	if (str->cap == 0)
		return (str);
	str->p = malloc(sizeof(char) * str->cap);
	if (!str->p)
		return (delete_string(str));
}
