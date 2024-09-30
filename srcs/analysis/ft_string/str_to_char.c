/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:16:25 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/30 17:09:13 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

char	*str_to_char_array(t_str *str)
{
	char	*arr;

	arr = ft_calloc(sizeof(char) * (str->len + 1));
	if (!arr)
		return (NULL);
	ft_memcpy(arr, str->data, str->len);
	return (arr);
}

void	*free_char_pntr_array(char **p_arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(p_arr[i]);
		i++;
	}
	free(p_arr);
	return (NULL);
}

char	**str_slice_to_char_pntr_array(t_str_slice *str_s)
{
	t_str_list	*str_l;
	t_str		*str;
	char		**p_arr;
	size_t		i;

	p_arr = ft_calloc(sizeof(char *) * (str_s->len + 1));
	if (!p_arr)
		return (NULL);
	p_arr[str_s->len] = NULL;
	str_l = str_s->list;
	i = 0;
	while (i < str_s->len)
	{
		str = str_l->str;
		p_arr[i] = str_to_char_array(str);
		if (!p_arr[i])
			return (free_char_pntr_array(p_arr, i));
		str_l = str_l->next;
		i++;
	}
	return (p_arr);
}
