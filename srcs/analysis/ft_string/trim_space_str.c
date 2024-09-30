/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_space_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:18:57 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/25 09:09:39 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
}

t_str	*trim_left_space_str(t_str **str_ref)
{
	t_str	*str;
	t_str	*new_str;
	size_t	i;

	str = *str_ref;
	i = 0;
	while (i < str->len && ft_isspace(str->data[i]))
		i++;
	if (!i)
		return (*str_ref);
	new_str = create_str_len(str->data + i, str->len - i);
	if (!new_str)
		return (NULL);
	delete_str(str);
	*str_ref = new_str;
}

void	trim_right_space_str(t_str *str)
{
	size_t	i;

	i = 0;
	while (i < str->len && ft_isspace(str->data[str->len - 1 - i]))
		i++;
	if (!i)
		return ;
	ft_memzero(str->data + str->len - i, i);
	str->len -= i;
	return ;
}

t_str	*trim_space_str(t_str **str_ref)
{
	if (!trim_left_space_str(str_ref))
		return (NULL);
	trim_right_space_str(*str_ref);
	return (*str_ref);
}
