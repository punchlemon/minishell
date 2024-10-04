/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_str_slice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:31:12 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/04 22:16:41 by retanaka         ###   ########.fr       */
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

void	*delete_str_slice(t_str_slice *str_s)
{
	if (str_s->list)
	{
		delete_str_list(str_s->list);
		str_s->len = 0;
		str_s->total_str_len = 0;
		str_s->list = NULL;
	}
	free(str_s);
	return (NULL);
}
