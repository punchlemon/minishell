/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_str_slice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:44:40 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/01 14:34:23 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	insert_str_list(t_str_list *dst_l, t_str_list *src_l)
{
	t_str_list	*dst_head;
	t_str_list	*dst_tail;
	t_str_list	*src_head;
	t_str_list	*src_tail;

	dst_head = dst_l;
	dst_tail = dst_head->next;
	src_head = src_l;
	src_tail = src_head->prev;
	dst_head->next = src_head;
	src_head->prev = dst_head;
	src_tail->next = dst_tail;
	dst_tail->prev = src_tail;
}

void	insert_str_slice_n(t_str_slice *dst_s, t_str_slice *src_s, size_t n)
{
	t_str_list	*src_l;

	src_l = src_s->list;
	insert_str_list(get_str_list_from_str_slice(dst_s, n), src_l);
	dst_s->len += src_s->len;
	dst_s->total_str_len += src_s->total_str_len;
}
