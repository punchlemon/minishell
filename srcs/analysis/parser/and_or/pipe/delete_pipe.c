/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:03:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 14:04:52 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd/cmd.h"
#include <stdlib.h>

void	*delete_pipe(t_pipe *pipe)
{
	pipe->cmd = delete_cmd(pipe->cmd);
	free(pipe);
	return (NULL);
}
