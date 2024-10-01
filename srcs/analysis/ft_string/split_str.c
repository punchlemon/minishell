/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:46:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/01 13:40:53 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

t_str	*split_str_in_two(t_str *str, size_t len)
{
	t_str		*str_right;

	str_right = create_str_len(str->data + len , str->len - len);
	if (!str_right)
		return (NULL);
	trim_right_str_n(str, len);
	return (str_right);
}

t_str_slice	*split_str_space_trail_space(t_str *str)
{
	t_str_slice	*str_s;
	int			flag;
	size_t		i;

	str_s = create_str_slice(str);
	if (!str_s)
		return (NULL);
	flag = 0;
	i = 0;
	while (i < str->len)
	{
		if (flag && !ft_isspace(str->data[i]))
		{
			if (!split_str_slice_end_n(str_s, i))
				return (delete_str_slice(str_s));
			flag = 0;
			i = 0;
			continue ;
		}
		else if (!flag && ft_isspace(str->data[i]))
			flag = 1;
		i++;
	}
	return (str_s);
}

t_str_slice	*split_str_space(t_str **str_ref)
{
	t_str_slice	*str_s;

	if (!trim_left_space_str(str_ref))
		return (NULL);
	str_s = split_str_space_trail_space(*str_ref);
	if (!str_s)
		return (NULL);
	return (trim_right_space_str_slice(str_s));
}
