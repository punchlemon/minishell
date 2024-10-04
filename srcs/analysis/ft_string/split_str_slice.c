/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str_slice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:14:41 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/04 18:44:56 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include <stdlib.h>

t_str_slice	*split_str_slice_end_n(t_str_slice *str_s, size_t n)
{
	t_str	*str;
	t_str	*tail;

	str = str_s->list->prev->str;
	tail = create_str_len(str->data + n, str->len - n);
	if (!tail)
		return (NULL);
	str->len = n;
	if (!append_str_slice_one_str_no_total(str_s, str))
		return (str_s->total_str_len -= (str->len - n), delete_str(str));
	return (str_s);
}

t_str_slice	*split_str_slice_space(t_str_slice *src_s)
{
	t_str_slice	*dst_s;
	t_str_slice	*tmp_s;
	t_str_list	*head_l;
	t_str_list	*str_l;

	dst_s = ft_calloc(sizeof(t_str_slice));
	if (!dst_s)
		return (NULL);
	head_l = src_s->list;
	str_l = head_l;
	while (1)
	{
		tmp_s = split_str_space(str_l->str);
		if (!tmp_s)
			return (NULL);
		append_str_slice(dst_s, tmp_s);
		delete_str_slice(tmp_s);
		str_l = str_l->next;
		if (str_l == head_l)
			return (dst_s);
	}
	return (NULL);
}
