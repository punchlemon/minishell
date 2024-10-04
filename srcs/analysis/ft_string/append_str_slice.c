/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_str_slice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:51:50 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/04 18:48:08 by retanaka         ###   ########.fr       */
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
	if (!str_s->len)
		str_s->list = str_l;
	else
		append_str_list_one(str_s->list, str_l);
	str_s->len++;
	return (str_s);
}

t_str_slice	*append_str_slice_one_str(t_str_slice *str_s, t_str *str)
{
	if (!append_str_slice_one_str_no_total(str_s, str))
		return (NULL);
	str_s->total_str_len += str->len;
	return (str_s);
}

t_str_slice	*append_str_slice(t_str_slice *dst_s, t_str_slice *src_s)
{
	t_str_list	*str_l;
	t_str_list	*head_l;
	t_str_list	*tmp_l;

	head_l = src_s->list;
	str_l = head_l;
	while (1)
	{
		tmp_l = create_str_list(str_l->str);
		if (!tmp_l)
			return (NULL);
		if (!dst_s->len)
			dst_s->list = tmp_l;
		else
			append_str_list_one(dst_s->list, tmp_l);
		dst_s->total_str_len += tmp_l->str->len;
		dst_s->len++;
		str_l = str_l->next;
		if (str_l == head_l)
			break ;
	}
	return (dst_s);
}
