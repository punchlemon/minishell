/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:53:24 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/29 16:24:16 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "ft_printf_stderr.h"
#include "libft.h"
#include "sig.h"

int	is_ambiguous_dir(t_red *reds, int i, int is_child)
{
	ft_printf_stderr("minishell: %s: ambiguous redirect\n", reds[i].target);
	while (i--)
		close(reds[i].file_fd);
	if (is_child)
		exit(1);
	else
		return (0);
}

int	cause_error_open_file(t_red *reds, size_t i, int is_child, int *status)
{
	ft_printf_stderr("minishell: %s: %s\n", reds[i].target,
		strerror(errno));
	while (i--)
		close(reds[i].file_fd);
	(void)status;
	if (is_child)
		exit(1);
	else
		return (0);
}

void	open_file(t_red *red)
{
	if (red->type == LESS)
	{
		red->file_fd = open(red->target, O_RDONLY);
		red->std_target_fd = 0;
	}
	else if (red->type == GREAT)
	{
		red->file_fd = open(red->target, \
				O_CREAT | O_RDWR | O_TRUNC, 0644);
		red->std_target_fd = 1;
	}
	else if (red->type == DGREAT)
	{
		red->file_fd = open(red->target, \
				O_CREAT | O_WRONLY | O_APPEND, 0644);
		red->std_target_fd = 1;
	}
}

int	open_all_file(t_red *reds, int is_child, int *status)
{
	size_t	i;

	i = 0;
	while (reds[i].type != TAIL)
	{
		if (reds[i].is_ambiguous)
			return (is_ambiguous_dir(reds, i, is_child));
		open_file(&reds[i]);
		if (g_signal == SIGINT)
			return (0);
		if (reds[i].file_fd < 0)
			return (cause_error_open_file(reds, i, is_child, status));
		i++;
	}
	return (1);
}
