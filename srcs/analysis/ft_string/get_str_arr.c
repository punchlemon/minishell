/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:43:33 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/06 19:26:48 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_str_list	*get_str_list_from_str_arr(t_str_arr *str_arr, size_t n)
{
	t_str_list	*l;

	l = str_arr->list;
	while (n--)
		l = l->next;
	return (l);
}
