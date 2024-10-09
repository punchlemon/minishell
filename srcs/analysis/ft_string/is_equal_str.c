/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_equal_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 21:38:06 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 13:59:38 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include "libft.h"

int	is_equal_str(t_str *str, char *src)
{
	size_t	n;

	n = ft_strlen(src);
	if (str->len != n)
		return (0);
	return (is_equal_mem(str->data, src, n));
}
