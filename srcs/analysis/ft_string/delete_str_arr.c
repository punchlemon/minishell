/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_str_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:31:12 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/06 19:24:41 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

void	*delete_str_list(t_str_list	*list)
{
	t_str_list	*start;
	t_str_list	*tmp;

	start = list;
	while (1)
	{
		list->str = delete_str(list->str);
		tmp = list->next;
		list->prev = NULL;
		list->next = NULL;
		free(list);
		if (tmp == start)
			return (NULL);
		list = tmp;
	}
	return (NULL);
}

void	*delete_str_arr(t_str_arr *str_arr)
{
	if (str_arr->list)
	{
		delete_str_list(str_arr->list);
		str_arr->len = 0;
		str_arr->total = 0;
		str_arr->list = NULL;
	}
	free(str_arr);
	return (NULL);
}
