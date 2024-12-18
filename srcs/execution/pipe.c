/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:17:11 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/24 14:23:47 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_printf_stderr.h"

int	prepare_pipe(t_cmd *cmd)
{
	t_cmd	*next_cmd;

	next_cmd = cmd + 1;
	if (next_cmd->type != TAIL)
	{
		if (pipe(cmd->pipe_out) < 0)
		{
			ft_printf_stderr("Error: %s: %s\n", "pipe", strerror(errno));
			return (1);
		}
		next_cmd->pipe_in[0] = cmd->pipe_out[0];
		next_cmd->pipe_in[1] = cmd->pipe_out[1];
	}
	return (0);
}

void	prepare_pipe_in_child(t_cmd *cmd)
{
	t_cmd	*next_cmd;

	next_cmd = cmd + 1;
	dup2(cmd->pipe_in[0], 0);
	if (cmd->pipe_in[0] != 0)
		close(cmd->pipe_in[0]);
	if (next_cmd->type != TAIL)
	{
		dup2(cmd->pipe_out[1], 1);
		if (cmd->pipe_out[1] != 1)
			close(cmd->pipe_out[1]);
	}
	if (cmd->pipe_out[0] != -1)
		close(cmd->pipe_out[0]);
}

void	prepare_pipe_in_parent(t_cmd *cmd)
{
	t_cmd	*next_cmd;

	next_cmd = cmd + 1;
	if (next_cmd->type != TAIL)
		close(cmd->pipe_out[1]);
	if (cmd->pipe_in[0] != 0)
		close(cmd->pipe_in[0]);
}
