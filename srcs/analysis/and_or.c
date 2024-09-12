/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:29:00 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/12 18:23:02 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_string.h"

char	**and_or(char *src)
{
	char			**res;
	t_string		*str;
	t_string_slice	*str_slice;

	str = create_string(src);
	if (!str)
		return (NULL);
	str->len--;
	str_slice = split_string(str);
	if (!str_slice)
		return (delete_string(str));
	delete_string(str);
	res = string_slice_to_char_array(str_slice);
	if (!res)
		return (delete_string_slice(str_slice));
	delete_string_slice(str_slice);
	return (res);
}
