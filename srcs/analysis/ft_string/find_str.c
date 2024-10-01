/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:03:59 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/23 21:56:46 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

int	find_first_index_from_str(t_str *target, t_str *key)
{
	size_t	i;
	if (key->len == 0)
		return (target->len);
	if (target->len < key->len)
		return (-1);
	i = 0;
	while (i < (target->len - key->len + 1))
	{
		if (is_equal_mem(target->data + i, key->data, key->len))
			return (i);
		i++;
	}
	return (-1);
}
