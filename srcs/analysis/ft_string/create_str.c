/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:27:23 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/01 16:23:18 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include <stdlib.h>

t_str	*create_str(char *src)
{
	t_str	*str;

	str = ft_calloc(sizeof(t_str));
	if (!str)
		return (NULL);
	str->len = ft_strlen(src);
	str->cap = 1;
	update_cap(str);
	str->data = ft_calloc(sizeof(char) * str->cap);
	if (!str->data)
		return (str->cap = 0, str->len = 0, free(str), NULL);
	ft_memcpy(str->data, src, str->len);
	return (str);
}

t_str	*create_str_len(char *src, size_t len)
{
	t_str	*str;

	str = ft_calloc(sizeof(t_str));
	if (!str)
		return (NULL);
	str->len = len;
	str->cap = 1;
	update_cap(str);
	str->data = ft_calloc(sizeof(char) * str->cap);
	if (!str->data)
		return (str->cap = 0, str->len = 0, free(str), NULL);
	ft_memcpy(str->data, src, str->len);
	return (str);
}
