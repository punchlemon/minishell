/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:21:30 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/06 19:23:52 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include <stdlib.h>

t_str_list	*create_str_list(t_str *str)
{
	t_str		*new;
	t_str_list	*list;

	list = ft_calloc(sizeof(t_str_list));
	if (!list)
		return (NULL);
	new = create_str_len(str->data, str->len);
	if (!new)
		return (free(list), NULL);
	list->next = list;
	list->prev = list;
	list->str = new;
	return (list);
}

t_str_arr	*create_str_arr(t_str *str)
{
	t_str_arr	*str_arr;

	str_arr = ft_calloc(sizeof(t_str_arr));
	if (!str_arr)
		return (NULL);
	str_arr->list = create_str_list(str);
	if (!str_arr->list)
		return (free(str_arr), NULL);
	str_arr->len = 1;
	str_arr->total = str->len;
	return (str_arr);
}
