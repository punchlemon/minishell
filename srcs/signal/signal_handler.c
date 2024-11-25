/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:00:43 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/25 19:37:29 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sig.h"

void	idle_handler(int signum)
{
	if (signum == SIGINT)
	{
		g_signal = signum;
		ft_putchar_fd('\n', STDERR_FILENO);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	heredoc_handler(int signum)
{
	if (signum == SIGINT)
	{
		g_signal = signum;
		ft_putchar_fd('\n', STDERR_FILENO);
	}
}

void	exec_handler(int signum)
{
	if (signum == SIGINT)
	{
		g_signal = signum;
		ft_putchar_fd('\n', STDERR_FILENO);
		rl_replace_line("", 0);
		rl_on_new_line();
	}
	else if (signum == SIGQUIT)
	{
		g_signal = signum;
		ft_putendl_fd("Quit (core dumped)", STDERR_FILENO);
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}
