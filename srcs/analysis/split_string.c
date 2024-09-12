/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:46:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/12 17:58:31 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

size_t	count_words(t_string *str)
{
	size_t	count;
	int		flag;
	size_t	i;

	if (!str || !str->p || !str->len)
		return (0);
	count = 0;
	flag = 0;
	i = 0;
	while (i < str->len)
	{
		if (flag == 0 && !is_space(str->p[i]))
		{
			flag = 1;
			count++;
		}
		else if (flag == 1 && is_space(str->p[i]))
			flag = 0;
		i++;
	}
	return (count);
}

size_t	get_word_len(t_string *str, size_t *j)
{
	size_t	word_len;

	word_len = 0;
	while (is_space(str->p[*j]) && *j < str->len)
		(*j)++;
	while (!is_space(str->p[*j]) && *j < str->len)
	{
		word_len++;
		(*j)++;
	}
	return (word_len);
}

t_string	*set_word(t_string *str_tmp, t_string *str, size_t *j)
{
	str_tmp->len = get_word_len(str, j);
	update_cap(str_tmp->len, &(str_tmp->cap));
	str_tmp->p = malloc(sizeof(char) * str_tmp->cap);
	if (!str_tmp->p)
		return (NULL);
	copy_bytes(str_tmp->p, str->p + *j - str_tmp->len, str_tmp->len);
	return (str_tmp);
}

t_string_slice	*split_string(t_string *str)
{
	t_string_slice	*str_slice;
	size_t			count;
	size_t			i;
	size_t			j;

	if (!str || !str->p || !str->len)
		return (NULL);
	count = count_words(str);
	str_slice = create_string_slice_len(count);
	if (!str_slice)
		return (NULL);
	j = 0;
	i = 0;
	while (i < count)
	{
		if (!set_word(str_slice->p + i, str, &j))
			return (delete_string_slice(str_slice));
		i++;
	}
	return (str_slice);
}
