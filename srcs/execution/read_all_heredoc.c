/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:54:11 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/29 17:14:56 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "sig.h"

int	read_heredoc_of_cmd(t_red *red, t_env *env, int *status)
{
	int		pipe_fds[2];
	int		tmp_in;

	tmp_in = dup(0);
	if (pipe(pipe_fds) < 0)
		return (ft_printf_stderr("Error : pipe\n"), *status = 1, *status);
	if (red->type == DLESS)
		read_heredoc_expand(red->target, pipe_fds, env, status);
	if (red->type == NO_EX_DLESS)
		read_heredoc(red->target, pipe_fds, status);
	dup2(tmp_in, 0);
	close(tmp_in);
	close(pipe_fds[1]);
	red->file_fd = pipe_fds[0];
	red->std_target_fd = 0;
	return (*status);
}

int	read_heredoc_of_cmds(t_cmd *cmds, t_env *env, int *status)
{
	size_t	i;
	size_t	j;

	set_heredoc_handler();
	i = 0;
	while (cmds[i].type != TAIL)
	{
		j = 0;
		while (cmds[i].reds[j].type != TAIL)
		{
			if (cmds[i].reds[j].type == DLESS
				|| cmds[i].reds[j].type == NO_EX_DLESS)
			{
				if (read_heredoc_of_cmd(&(cmds[i].reds[j]), env, status))
					return (*status);
			}
			j++;
		}
		i++;
	}
	set_exec_handler(false);
	return (0);
}
