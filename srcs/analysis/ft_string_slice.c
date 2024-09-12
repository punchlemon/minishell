/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_slice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:31:40 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/12 18:22:10 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string_slice	*create_string_slice(t_string *str)
{
	t_string_slice	*str_slice;

	str_slice = malloc(sizeof(t_string_slice));
	if (!str_slice)
		return (NULL);
	mem_zero(str_slice, sizeof(t_string_slice));
	if (!str)
		return (str_slice);
	str_slice->len = 1;
	str_slice->cap = 1;
	str_slice->p = str;
	return (str_slice);
}

t_string_slice	*create_string_slice_len(size_t len)
{
	t_string_slice	*str_slice;

	str_slice = malloc(sizeof(t_string_slice));
	if (!str_slice)
		return (NULL);
	mem_zero(str_slice, sizeof(t_string_slice));
	if (len == 0)
		return (str_slice);
	str_slice->len = len;
	if (update_cap(str_slice->len, &(str_slice->cap)) == -1)
		return (delete_string_slice(str_slice));
	str_slice->p = malloc(sizeof(t_string) * str_slice->cap);
	if (!str_slice->p)
		return (delete_string_slice(str_slice));
	mem_zero(str_slice->p, str_slice->cap);
	return (str_slice);
}

void	*delete_string_slice(t_string_slice *str_slice)
{
	size_t		i;
	t_string	*str;

	if (str_slice && str_slice->p && str_slice->len)
	{
		i = 0;
		while (i < str_slice->len)
		{
			str = str_slice->p + i;
			mem_zero(str->p, str->cap);
			free(str->p);
			mem_zero(str, sizeof(t_string));
			i++;
		}
		mem_zero(str_slice, sizeof(t_string_slice));
	}
	free(str_slice);
	return (NULL);
}

void	put_string_slice(t_string_slice *str_slice, int *len)
{
	int		tmp;
	size_t	i;

	i = 0;
	while (i < str_slice->len)
	{
		put_string(str_slice->p + i++, len);
		if (*len == -1)
			return ;
		tmp = write(1, ", ", 2);
		if (tmp == -1)
			return (*len = -1, (void)tmp);
		*len += tmp;
	}
	return ;
}

// t_string_slice	*devide_string_slice_len(t_string_slice *str_slice
// 	, size_t n, size_t len)
// {
// 	t_string_slice	*res;
// 	t_string		**tmp;
//
// 	if (str_slice->len < str_slice->cap)
// 	{
// 		res = str_slice;
// 	}
// 	else
// 	{
// 		tmp = res->p;
// 		res->p = malloc(sizeof(t_string *) *
// 	}
// 	return (res);
// }
