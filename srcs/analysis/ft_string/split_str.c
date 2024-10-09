/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:46:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 12:21:07 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

size_t	count_word_len(char *src)
{
	char	c;
	size_t	i;

	i = 0;
	while (1)
	{
		c = src[i];
		if (ft_isspace(c) || !c)
			break ;
		i++;
	}
	return (i);
}

t_str_arr	*split_str_space(t_str *str)
{
	t_str_arr	*str_arr;
	t_str		*tmp;
	size_t		l;
	size_t		i;

	str_arr = ft_calloc(sizeof(t_str_arr));
	if (!str_arr)
		return (NULL);
	i = 0;
	while (i < str->len)
	{
		if (!ft_isspace(str->data[i]))
		{
			l = count_word_len(str->data + i);
			tmp = create_str_len(str->data + i, l);
			if (!append_str_arr_one_str(str_arr, tmp))
				return (delete_str_arr(str_arr));
			i += l;
		}
		i++;
	}
	return (str_arr);
}
