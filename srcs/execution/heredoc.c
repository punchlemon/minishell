/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:45:01 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/26 17:24:35 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "ft_printf_stderr.h"
#include "sig.h"
#include "libft.h"

int	get_heredoc(char *delimiter, int is_child, int *status)
{
	int		pipe_fds[2];

	if (!is_child)
		set_heredoc_handler();
	if (pipe(pipe_fds) < 0)
	{
		ft_printf_stderr("Error : pipe\n");
		exit(1);
	}
	read_heredoc(delimiter, pipe_fds, status);
	close(pipe_fds[1]);
	return (pipe_fds[0]);
}

int	get_heredoc_expand(char *delimiter, int is_child, t_env *env, int *status)
{
	int		pipe_fds[2];

	if (!is_child)
		set_heredoc_handler();
	if (pipe(pipe_fds) < 0)
	{
		ft_printf_stderr("Error : pipe\n");
		exit(1);
	}
	read_heredoc_expand(delimiter, pipe_fds, env, status);
	close(pipe_fds[1]);
	return (pipe_fds[0]);
}
