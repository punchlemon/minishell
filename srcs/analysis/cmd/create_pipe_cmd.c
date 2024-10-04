/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:29:40 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/04 19:03:02 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include "minishell.h"

t_pipe_cmd	*create_pipe_cmd(t_str *str)
{
	t_pipe_cmd	*p_cmd;
	t_str_slice	*str_s;

	str_s = split_str_space(str);
	if (!str_s)
		return (NULL);
	p_cmd = ft_calloc(sizeof(t_pipe_cmd));
	if (!p_cmd)
		return (delete_str_slice(str_s));
	p_cmd->str_s = str_s;
	return (p_cmd);
}
