/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_edge_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:09:21 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/25 13:08:40 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	trim_right_str_n(t_str *str, size_t n)
{
	str->len -= n;
	while (n--)
		str->data[str->len - n] = '\0';
}

t_str	*trim_left_edge_str(t_str **str_ref)
{
	t_str	*str;
	t_str	*new_str;

	str = *str_ref;
	new_str = create_str_len(str->data + 1, str->len - 1);
	if (!new_str)
		return (NULL);
	delete_str(str);
	*str_ref = new_str;
	return (*str_ref);
}

void	trim_right_edge_str(t_str *str)
{
	str->data[str->len - 1] = '\0';
	str->len--;
}

t_str	*trim_edge_str(t_str **str_ref)
{
	if (!trim_left_edge_str(str_ref))
		return (NULL);
	trim_right_edge_str(*str_ref);
	return (*str_ref);
}
