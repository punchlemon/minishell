/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 01:56:33 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/04 18:49:06 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"
#include "minishell.h"

t_str_slice *split_str_and_or_init(t_str *str)
{
	t_str_slice	*str_s;

	str_s = create_str_slice(str);
	if (!str_s)
		return (NULL);
	return (str_s);
}

t_str_slice	*split_str_ref_and_or(t_str **str_ref)
{
	t_str_slice	*str_s;
	t_str		*str;
	size_t		i;
	size_t		l;

	str = trim_space_str(str_ref);
	if (!str)
		return (NULL);
	if (!str->len)
		return (split_str_and_or_init(str));
	str_s = ft_calloc(sizeof(t_str_slice));
	if (!str_s)
		return (NULL);
	i = 0;
	l = 0;
	while (i + l < str->len)
	{
		if (!move_word(str_s, str->data + i, &i, &l))
			return (delete_str_slice(str_s));
	}
	str = create_str_len(str->data + i, l);
	if (!str || !append_str_slice_one_str(str_s, str))
		return (NULL);
	return (str_s);
}

t_cmd_node	*and_or(t_str **str_ref)
{
	t_str_slice	*str_s;
	t_str_slice	*split_s;
	t_cmd_node	*cmd_n;

	str_s = split_str_ref_and_or(str_ref);
	if (!str_s)
		return (NULL);
	split_s = split_str_slice_space(str_s);
	delete_str_slice(str_s);
	if (!split_s)
		return (NULL);
	cmd_n = create_cmd_node(split_s);
	if (!cmd_n)
		return (delete_cmd_node(cmd_n));
	return (cmd_n);
}
