/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:31:19 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/12 12:37:42 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "libft_extend.h"
#include <stdlib.h>

void	*delete_cmd(t_cmd *cmd)
{
	cmd->in = 0;
	cmd->out = 0;
	free_pp(cmd->argv);
	cmd->argv = NULL;
	free(cmd);
	return (NULL);
}
