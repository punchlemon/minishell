/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 01:56:33 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 14:23:45 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"
#include "and_or.h"

t_str_arr	*split_str_and_or_init(t_str *str)
{
	t_str_arr	*str_arr;

	str_arr = create_str_arr(str);
	if (!str_arr)
		return (NULL);
	return (str_arr);
}

t_str_arr	*split_str_ref_and_or(t_str **str_ref)
{
	t_str_arr	*str_arr;
	t_str		*str;
	size_t		i;
	size_t		l;

	str = trim_space_str(str_ref);
	if (!str)
		return (NULL);
	if (!str->len)
		return (split_str_and_or_init(str));
	str_arr = ft_calloc(sizeof(t_str_arr));
	if (!str_arr)
		return (NULL);
	i = 0;
	l = 0;
	while (i + l < str->len)
	{
		if (!move_word(str_arr, str->data + i, &i, &l))
			return (delete_str_arr(str_arr));
	}
	if (!str)
		return (NULL);
	if (!append_str_arr_one_src_len(str_arr, str->data + i, l))
		return (delete_str(str));
	return (str_arr);
}

t_and_or	*and_or(t_str **str_ref)
{
	t_str_arr	*str_arr;
	t_and_or	*and_or;

	str_arr = split_str_ref_and_or(str_ref);
	if (!str_arr)
		return (NULL);
	and_or = create_and_or(str_arr);
	delete_str_arr(str_arr);
	if (!and_or)
		return (NULL);
	return (and_or);
}
