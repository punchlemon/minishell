/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:31:19 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 12:31:30 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*delete_cmd(t_cmd *cmd)
{
	cmd->in = 0;
	cmd->out = 0;
	cmd->argv = free_char_pp(cmd->argv);
	free(cmd);
	return (NULL);
}
