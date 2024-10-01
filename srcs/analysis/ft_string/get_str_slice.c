/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_slice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:43:33 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/01 14:33:15 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_str_list	*get_str_list_from_str_slice(t_str_slice *str_s, size_t n)
{
	t_str_list	*l;

	l = str_s->list;
	while (n--)
		l = l->next;
	return (l);
}

// char	get_char_from_str_slice(t_str_slice *str_s, size_t n)
// {
// 	size_t		i;
// 	t_str_list	*list;
// 	t_str		*str;

// 	i = 0;
// 	while (i < str_s->len)
// 	{
// 		str = get_str_list_from_str_slice(str_s, i)->str;
// 		if (str->len > n)
// 			return (str->data[n]);
// 		else
// 			n -= str->len;
// 		i++;
// 	}
// 	return (0);
// }

// t_str_list	*get_list_containing_n_char(t_str_slice *str_s, size_t n)
// {
// 	size_t		i;
// 	t_str_list	*str_l;

// 	str_l = str_s->list;
// 	i = 0;
// 	while (i < str_s->len)
// 	{
// 		if (n < str_l->str->len)
// 			return (str_l);
// 		else
// 			n -= str_l->str->len;
// 		str_l = str_l->next;
// 	}
// 	return (NULL);
// }
