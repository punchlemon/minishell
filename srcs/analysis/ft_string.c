/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:34:18 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/12 18:22:20 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_string.h"

void	*delete_string(t_string *str)
{
	if (str && str->p)
	{
		mem_zero(str->p, str->cap);
		free(str->p);
		mem_zero(str, sizeof(t_string));
	}
	free(str);
	return (NULL);
}

t_string	*create_string(char *src)
{
	t_string	*str;

	str = malloc(sizeof(t_string));
	if (!str)
		return (NULL);
	mem_zero(str, sizeof(t_string));
	if (!src)
		return (str);
	str->len = ft_strlen(src);
	if (update_cap(str->len, &(str->cap)) == -1)
		return (delete_string(str));
	if (str->cap == 0)
		return (str);
	str->p = malloc(sizeof(char) * str->cap);
	if (!str->p)
		return (delete_string(str));
	mem_zero(str->p, str->cap);
	copy_bytes(str->p, src, str->len);
	return (str);
}

t_string	*create_string_len(size_t len)
{
	t_string	*str;

	str = malloc(sizeof(t_string));
	if (!str)
		return (NULL);
	mem_zero(str, sizeof(t_string));
	if (len == 0)
		return (str);
	str->len = len;
	if (update_cap(str->len, &str->cap) == -1)
		return (delete_string(str));
	str->p = malloc(sizeof(char) * str->cap);
	if (!str->p)
		return (delete_string(str));
	mem_zero(str->p, str->cap);
	return (str);
}

void	put_string(t_string *str, int *len)
{
	int	tmp;

	tmp = write(1, str->p, str->len);
	if (tmp == -1)
		*len = -1;
	else
		*len += tmp;
}
