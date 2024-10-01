/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str_slice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:14:41 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/01 14:12:20 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

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

t_str_slice	*split_str_slice_end_n(t_str_slice *str_s, size_t n)
{
	t_str	*str;
	t_str	*tail;

	str = str_s->list->prev->str;
	tail = create_str_len(str->data + n, str->len - n);
	if (!tail)
		return (NULL);
	str->len = n;
	if (!append_str_slice_one_str_no_total(str_s, str))
		return (str_s->total_str_len -= (str->len - n), delete_str(str));
	return (str_s);
}

t_str_slice	*split_str_slice_space(t_str_slice *str_s)
{
	t_str_list	*str_l;
	t_str_slice	*tmp_s;
	size_t		i;

	str_l = str_s->list;
	while (i < str_s->len)
	{
		tmp_s = split_str_space(&(str_l->str));
		if (!tmp_s)
			return (NULL);
		insert_str_slice_n(str_s, tmp_s, i);// 多分remove_listみたいなことしないといけない
		i += tmp_s->len;
		clear_str_slice(tmp_s);
	}
	return (str_s);
}
