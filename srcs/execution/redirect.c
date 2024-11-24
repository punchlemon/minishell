/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:16:40 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/24 18:54:09 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "ft_printf_stderr.h"
#include "libft.h"

void	do_redirect(t_red *red)
{
	if (red->file_fd != -1 && red->std_target_fd != -1)
	{
		if (dup2(red->file_fd, red->std_target_fd) < 0)
		{
			ft_printf_stderr("Error : dup2\n");
			exit(1);
		}
	}
	if (red->file_fd != -1)
		close(red->file_fd);
}

void	set_redirects(t_red *reds)
{
	size_t	i;

	i = 0;
	while (reds[i].type != TAIL)
	{
		do_redirect(&reds[i]);
		i++;
	}
}
