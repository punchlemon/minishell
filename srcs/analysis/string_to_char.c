/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:16:25 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/12 17:57:41 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*string_to_char(t_string *str)
{
	char	*p;

	p = malloc(sizeof(char) * (str->len + 1));
	if (!p)
		return (NULL);
	p[str->len] = '\0';
	copy_bytes(p, str->p, str->len);
	return (p);
}

char	**string_slice_to_char_array(t_string_slice *str_slice)
{
	char	**pp;
	size_t	i;
	size_t	j;

	pp = malloc(sizeof(char *) * (str_slice->len + 1));
	if (!pp)
		return (NULL);
	pp[str_slice->len] = NULL;
	i = -1;
	while (++i < str_slice->len)
	{
		pp[i] = string_to_char(str_slice->p + i);
		if (!pp[i])
		{
			j = -1;
			while (++j < i)
			{
				mem_zero(pp[j], (str_slice->p + j)->len + 1);
				free(pp[j]);
			}
			return (mem_zero(pp, str_slice->len + 1), free(pp), NULL);
		}
	}
	return (pp);
}
