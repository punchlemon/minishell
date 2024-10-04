/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:46:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/04 18:29:37 by retanaka         ###   ########.fr       */
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

t_str_slice	*split_str_space(t_str *str)
{
	t_str_slice	*str_s;
	t_str		*tmp;
	size_t		l;
	size_t		i;

	str_s = ft_calloc(sizeof(t_str_slice));
	if (!str_s)
		return (NULL);
	i = 0;
	while (i < str->len)
	{
		if (!ft_isspace(str->data[i]))
		{
			l = count_word_len(str->data + i);
			tmp = create_str_len(str->data + i, l);
			if (!append_str_slice_one_str(str_s, tmp))
				return (delete_str_slice(str_s));
			i += l;
		}
		i++;
	}
	return (str_s);
}
/// iとlをsplit_str_spaceだけで管理して、iのアドレスを渡すことで管理した方がいいと思う
