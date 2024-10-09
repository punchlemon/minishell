/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_str_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:51:50 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/06 19:23:12 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	append_str_list_one(t_str_list *dst_l, t_str_list *src_l)
{
	t_str_list	*dst_head;
	t_str_list	*dst_tail;

	dst_head = dst_l;
	dst_tail = dst_head->prev;
	dst_head->prev = src_l;
	src_l->next = dst_head;
	src_l->prev = dst_tail;
	dst_tail->next = src_l;
}

t_str_arr	*append_str_arr_one_str_no_total(t_str_arr *str_arr, t_str *str)
{
	t_str_list	*str_l;

	str_l = create_str_list(str);
	if (!str_l)
		return (NULL);
	if (!str_arr->len)
		str_arr->list = str_l;
	else
		append_str_list_one(str_arr->list, str_l);
	str_arr->len++;
	return (str_arr);
}

t_str_arr	*append_str_arr_one_str(t_str_arr *str_arr, t_str *str)
{
	if (!append_str_arr_one_str_no_total(str_arr, str))
		return (NULL);
	str_arr->total += str->len;
	return (str_arr);
}

t_str_arr	*append_str_arr_one_src_len(t_str_arr *str_arr, char *src
	, size_t len)
{
	t_str	*str;

	str = create_str_len(src, len);
	if (!str)
		return (NULL);
	if (!append_str_arr_one_str(str_arr, str))
		return (delete_str(str));
	return (str_arr);
}

t_str_arr	*append_str_arr(t_str_arr *dst_arr, t_str_arr *src_arr)
{
	t_str_list	*str_l;
	t_str_list	*head_l;
	t_str_list	*tmp_l;

	head_l = src_arr->list;
	str_l = head_l;
	while (1)
	{
		tmp_l = create_str_list(str_l->str);
		if (!tmp_l)
			return (NULL);
		if (!dst_arr->len)
			dst_arr->list = tmp_l;
		else
			append_str_list_one(dst_arr->list, tmp_l);
		dst_arr->total += tmp_l->str->len;
		dst_arr->len++;
		str_l = str_l->next;
		if (str_l == head_l)
			break ;
	}
	return (dst_arr);
}
