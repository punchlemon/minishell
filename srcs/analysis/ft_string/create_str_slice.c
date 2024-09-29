/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str_slice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:28:19 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/27 22:49:10 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

t_str_list	*create_str_list(t_str *str)
{
	t_str		*new;
	t_str_list	*list;

	list = ft_calloc(sizeof(t_str_list));
	if (!list)
		return (NULL);
	new = create_str(str->data);
	if (!new)
		return (free(list), NULL);
	list->next = list;
	list->prev = list;
	list->str = new;
	return (list);
}

t_str_slice	*create_str_slice(t_str *str)
{
	t_str_slice	*str_s;

	str_s = ft_calloc(sizeof(t_str_slice));
	if (!str_s)
		return (NULL);
	str_s->list = create_str_list(str);
	if (!str_s->list)
		return (free(str_s), NULL);
	str_s->len = 1;
	str_s->total_str_len = str->len;
	return (str_s);
}
