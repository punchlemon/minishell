/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_slice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:31:40 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/24 03:55:13 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

int	put_str_slice(t_str_slice *str_s, int *len)
{
	t_str	*str;
	int		tmp;
	size_t	i;

	i = 0;
	while (i < str_s->len)
	{
		str = get_str_list_from_str_slice(str_s, i)->str;
		tmp += write(1, "\"", 1);
		tmp += put_str(str, len);
		tmp += write(1, "\"", 1);
		if (i == str_s->len - 1)
			break ;
		tmp += write(1, ", ", 2);
		i++;
	}
	*len += tmp;
	return (tmp);
}
