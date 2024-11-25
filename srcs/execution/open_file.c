/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:53:24 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/24 21:50:41 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "ft_printf_stderr.h"
#include "libft.h"

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

int	cause_error_open_file(t_red *reds, size_t i, int is_child)
{
	ft_printf_stderr("minishell: %s: %s\n", reds[i].target,
		strerror(errno));
	while (i--)
		close(reds[i].file_fd);
	if (is_child)
		exit(1);
	else
		return (0);
}

void	open_file(t_red *reds, size_t i, t_env *env, char *st)
{
	if (reds[i].type == LESS)
	{
		reds[i].file_fd = open(reds[i].target, O_RDONLY);
		reds[i].std_target_fd = 0;
	}
	else if (reds[i].type == GREAT)
	{
		reds[i].file_fd = open(reds[i].target, \
				O_CREAT | O_RDWR | O_TRUNC, 0644);
		reds[i].std_target_fd = 1;
	}
	else if (reds[i].type == DLESS || reds[i].type == NO_EX_DLESS)
	{
		if (reds[i].type == DLESS)
			reds[i].file_fd = get_heredoc_expand(reds[i].target, env, st);
		if (reds[i].type == NO_EX_DLESS)
			reds[i].file_fd = get_heredoc(reds[i].target);
		reds[i].std_target_fd = 0;
	}
	else if (reds[i].type == DGREAT)
	{
		reds[i].file_fd = open(reds[i].target, \
				O_CREAT | O_WRONLY | O_APPEND, 0644);
		reds[i].std_target_fd = 1;
	}
}

int	open_all_file(t_red *reds, int is_child, t_env *env, int status)
{
	size_t	i;
	char	*str_status;

	str_status = ft_itoa(status);
	if (str_status == NULL)
		exit(1);
	i = 0;
	while (reds[i].type != TAIL)
	{
		if (reds[i].is_ambiguous)
			return (is_ambiguous_dir(reds, i, is_child));
		open_file(reds, i, env, str_status);
		if (reds[i].file_fd < 0)
			return (cause_error_open_file(reds, i, is_child));
		i++;
	}
	free(str_status);
	return (1);
}