/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:14:41 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/06 19:39:19 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include <stdlib.h>

t_str_arr	*split_str_arr_end_n(t_str_arr *str_arr, size_t n)
{
	t_str	*str;
	t_str	*tail;

	str = str_arr->list->prev->str;
	tail = create_str_len(str->data + n, str->len - n);
	if (!tail)
		return (NULL);
	str->len = n;
	if (!append_str_arr_one_str_no_total(str_arr, str))
		return (str_arr->total -= (str->len - n), delete_str(str));
	return (str_arr);
}

t_str_arr	*split_str_arr_space(t_str_arr *src_arr)
{
	t_str_arr	*dst_arr;
	t_str_arr	*tmp_arr;
	t_str_list	*head_l;
	t_str_list	*str_l;

	dst_arr = ft_calloc(sizeof(t_str_arr));
	if (!dst_arr)
		return (NULL);
	head_l = src_arr->list;
	str_l = head_l;
	while (1)
	{
		tmp_arr = split_str_space(str_l->str);
		if (!tmp_arr)
			return (NULL);
		append_str_arr(dst_arr, tmp_arr);
		delete_str_arr(tmp_arr);
		str_l = str_l->next;
		if (str_l == head_l)
			return (dst_arr);
	}
	return (NULL);
}
