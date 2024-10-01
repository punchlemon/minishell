/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_str_slice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:22:10 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/01 16:25:52 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_str_list	*remove_str_list(t_str_list *str_l)
{
	t_str_list	*prev;
	t_str_list	*next;

	prev = str_l->prev;
	next = str_l->next;
	delete_str_list(str_l);
	if (prev == str_l)
		return (NULL);
	prev->next = next;
	next->prev = prev;
	return (prev);
}

t_str_slice	*remove_str_slice_n(t_str_slice *str_s, size_t n)
{
	t_str_list	*str_l;

	str_l = get_str_list_from_str_slice(str_s, n);
	str_s->len--;
	str_s->total_str_len -= str_l->str->len;
	if (!remove_str_list(str_l))
		return (str_s->len = 0, str_s->total_str_len = 0, str_s->list = NULL
			, NULL);
	return (str_s);
}
