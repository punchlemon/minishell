/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_str_slice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:51:50 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/27 22:30:11 by retanaka         ###   ########.fr       */
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

t_str_slice	*append_str_slice_one_str_no_total(t_str_slice *str_s, t_str *str)
{
	t_str_list	*str_l;

	str_l = create_str_list(str);
	if (!str_l)
		return (NULL);
	append_str_list_one(str_s->list->prev, str_l);
	str_s->len++;
	retrun (str_s);
}

t_str_slice	*append_str_slice_one_str(t_str_slice *str_s, t_str *str)
{
	if (!append_str_slice_one_str_no_total(str_s, str))
		return (NULL);
	str_s->total_str_len += str->len;
	return (str_s);
}
