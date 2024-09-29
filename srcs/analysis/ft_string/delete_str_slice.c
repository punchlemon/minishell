/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_str_slice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:31:12 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/30 06:46:54 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*delete_str_list(t_str_list	*list)
{
	t_str_list	*start;
	t_str_list	*l;
	t_str_list	*tmp;

	start = list;
	while (1)
	{
		l->str = delete_str(l->str);
		tmp = l->next;
		l->prev = NULL;
		l->next = NULL;
		free(l);
		if (tmp == start)
			return (NULL);
		l = tmp;
	}
}

void	*delete_str_slice(t_str_slice *str_s)
{
	delete_str_list(str_s->list);
	str_s->len = 0;
	str_s->total_str_len = 0;
	str_s->list = NULL;
	free(str_s);
	return (NULL);
}
