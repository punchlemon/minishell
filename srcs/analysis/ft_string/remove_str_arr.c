/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_str_slice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:22:10 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/06 19:26:34 by retanaka         ###   ########.fr       */
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

t_str_arr	*remove_str_arr_n(t_str_arr *str_arr, size_t n)
{
	t_str_list	*str_l;

	str_l = get_str_list_from_str_arr(str_arr, n);
	str_arr->len--;
	str_arr->total -= str_l->str->len;
	if (!remove_str_list(str_l))
		return (str_arr->len = 0, str_arr->total = 0, str_arr->list = NULL
			, NULL);
	return (str_arr);
}
