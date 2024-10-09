/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:26:13 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 12:26:49 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include "minishell.h"

t_cmd	*create_cmd(t_str *str)
{
	t_cmd	*cmd;
	t_str_arr	*str_arr;

	str_arr = split_str_space(str);
	if (!str_arr)
		return (NULL);
	cmd = ft_calloc(sizeof(t_cmd));
	cmd->argv = convert_str_arr_to_char_pp(str_arr);
	delete_str_arr(str_arr);
	if (!cmd->argv)
		return (NULL);
	cmd->in = 0;
	cmd->out = 0;///// io_redirectによってfdが入れられる
	return (cmd);
}
