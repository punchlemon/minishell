/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_space_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:18:57 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/01 16:28:56 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

t_str	*trim_left_space_str(t_str **str_ref)
{
	t_str	*str;
	t_str	*new_str;
	size_t	i;

	str = *str_ref;
	i = 0;
	while (i < str->len && ft_isspace(str->data[i]))
		i++;
	if (!i)
		return (*str_ref);
	new_str = create_str_len(str->data + i, str->len - i);
	if (!new_str)
		return (NULL);
	delete_str(str);
	*str_ref = new_str;
	return (*str_ref);
}

size_t	trim_right_space_str(t_str *str)
{
	size_t	i;

	i = 0;
	while (i < str->len && ft_isspace(str->data[str->len - 1 - i]))
		i++;
	if (!i)
		return (i);
	ft_memzero(str->data + str->len - i, i);
	str->len -= i;
	return (i);
}

t_str_slice	*trim_right_space_str_slice(t_str_slice *str_s)
{
	t_str_list	*head_l;
	t_str_list	*str_l;

	head_l = str_s->list;
	str_l = head_l;
	while (1)
	{
		str_s->total_str_len -= trim_right_space_str(str_l->str);
		str_l = str_l->next;
		if (str_l == head_l)
			return (str_s);
	}
}

t_str	*trim_space_str(t_str **str_ref)
{
	if (!trim_left_space_str(str_ref))
		return (NULL);
	trim_right_space_str(*str_ref);
	return (*str_ref);
}
