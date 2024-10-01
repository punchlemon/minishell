/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 01:56:33 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/01 13:33:53 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_string.h"

t_str_slice	*split_str_and_or(t_str *str)
{
	t_str_slice	*str_s;
	char		c;
	int			flag;
	size_t		i;

	str_s = create_str_slice(str);
	if (!str_s)
		return (NULL);
	flag = 0;
	i = 0;
	while (i < str->len)
	{
		c = str->data[i];
		if (!flag && (c == '&' || c == '|')
			|| flag && !(c == '&' || c == '|' || ft_isspace(c)))
		{
			if (!split_str_slice_end_n(str_s, i))
				return (delete_str_slice(str_s));
			flag = !flag;
			i = 0;
			continue ;
		}
		i++;
	}
	return (trim_right_space_str_slice(str_s));
}

t_cmd_node	*and_or(t_str *str)
{
	t_str_slice	*str_s;
	t_cmd_node	*cmd_n;

	if (!is_valid_str_and_or(str))
		return (NULL);
	if (!split_str_and_or(str))
		return (NULL);
	cmd_n = create_cmd_node(str_s);
	if (!cmd_n)
		return (delete_cmd_node(cmd_n));
	return (cmd_n);
}
