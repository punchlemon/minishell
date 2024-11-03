#include "minishell.h"

void	prepare_pipe(t_cmd *cmd)
{
	t_cmd	*next_cmd;

	next_cmd = cmd + 1;
	if (next_cmd->type != TAIL)
	{
		if (pipe(cmd->pipe_out) < 0)
			exit(1); // error pipe
		next_cmd->pipe_in[0] = cmd->pipe_out[0];
		next_cmd->pipe_in[1] = cmd->pipe_out[1];
	}
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
