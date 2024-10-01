/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:29:40 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/01 16:19:03 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include "minishell.h"

t_pipe_cmd	*create_pipe_cmd(t_str_slice *str_s)
{
	t_pipe_cmd	*p_cmd;

	p_cmd = ft_calloc(sizeof(t_pipe_cmd));
	if (!p_cmd)
		return (NULL);
	p_cmd->str_s = str_s;
	return (p_cmd);
}
