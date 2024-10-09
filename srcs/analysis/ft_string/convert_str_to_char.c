/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str_to_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:16:25 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/06 19:23:30 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include <stdlib.h>

char	*convert_str_to_char_p(t_str *str)
{
	char	*p;

	p = ft_calloc(sizeof(char) * (str->len + 1));
	if (!p)
		return (NULL);
	ft_memcpy(p, str->data, str->len);
	return (p);
}

void	*free_char_pp(char **pp)
{
	size_t	i;

	i = 0;
	while (pp[i])
	{
		free(pp[i]);
		i++;
	}
	free(pp);
	return (NULL);
}

char	**convert_str_arr_to_char_pp(t_str_arr *str_arr)
{
	t_str_list	*str_l;
	t_str		*str;
	char		**pp;
	size_t		i;

	pp = ft_calloc(sizeof(char *) * (str_arr->len + 1));
	if (!pp)
		return (NULL);
	str_l = str_arr->list;
	i = 0;
	while (i < str_arr->len)
	{
		str = str_l->str;
		pp[i] = convert_str_to_char_p(str);
		if (!pp[i])
			return (free_char_pp(pp));
		str_l = str_l->next;
		i++;
	}
	return (pp);
}
