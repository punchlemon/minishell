/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:03:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 12:31:08 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*delete_pipe(t_pipe *pipe)
{
	pipe->cmd = delete_cmd(pipe->cmd);
	free(pipe);
	return (NULL);
}
