/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:31:40 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/06 19:36:37 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

void	put_str_arr(t_str_arr *str_arr)
{
	t_str_list	*head_l;
	t_str_list	*str_l;

	head_l = str_arr->list;
	str_l = head_l;
	put("[len:");
	put_size_t(str_arr->len);
	put(" total:");
	put_size_t(str_arr->total);
	put(" {");
	while (1)
	{
		put_str_no_nl(str_l->str);
		str_l = str_l->next;
		if (str_l == head_l)
			break ;
		put(", ");
	}
	put("}]\n");
}

int	put_str_arr_len(t_str_arr *str_arr, int *len)
{
	t_str	*str;
	int		tmp;
	size_t	i;

	tmp = 0;
	i = 0;
	while (i < str_arr->len)
	{
		str = get_str_list_from_str_arr(str_arr, i)->str;
		tmp += write(1, "\"", 1);
		tmp += put_str_len(str, len);
		tmp += write(1, "\"", 1);
		if (i == str_arr->len - 1)
			break ;
		tmp += write(1, ", ", 2);
		i++;
	}
	*len += tmp;
	return (tmp);
}
