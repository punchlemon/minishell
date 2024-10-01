/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_pipe_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:03:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/30 19:31:56 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*delete_pipe_cmd(t_pipe_cmd *p_cmd)
{
	p_cmd->str_s = delete_str_slice(p_cmd->str_s);
	free(p_cmd);
	return (NULL);
}
