/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:46:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/30 22:31:08 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

t_str	*split_str_in_two(t_str *str, size_t len)
{
	t_str		*str_right;

	str_right = create_str_len(str->data + len , str->len - len);
	if (!str_right)
		return (NULL);
	trim_right_str_n(str, len);
	return (str_right);
}

t_str	*split_str_n_and_append(t_str_slice *str_s, t_str **str_ref, size_t n)
{
	t_str		*head;
	t_str		*tail;

	head = *str_ref;
	tail = split_str_in_two(head, n);
	if (!tail)
		return (NULL);
	if (!append_str_slice_one_str_no_total(str_s, tail))
		return (delete_str(tail));
	*str_ref = tail;
	return (*str_ref);
}

t_str_slice	*split_str_space(t_str *str)
{
	t_str_slice	*str_s;
	char		c;
	int			flag;
	size_t		i;

	str_s = create_str_slice(str);
	if (!str_s)
		return (NULL);
	flag = is_space(str->data[0]);
	i = 0;
	while (i < str->len)
	{
		c = str->data[i];
		if (flag != is_space(c))
		{
			if (!split_str_n_and_append(str_s, &str, i))
				return (delete_str_slice(str_s));
			i = 0;
			flag = !flag;
		}
		i++;
	}
	return (str_s);
}
// この関数は大いに修正される必要あり
// 空白flagが立ち下がりのタイミングから立ち上がりのタイミングまでのstrを切り取る関数を作成して
// str_sにappendするべき

// split_str_n_and_append is not public function.
