/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:16:40 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/22 23:40:17 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "ft_printf_stderr.h"
#include "libft.h"

// int	get_heredoc(char *delimiter) // have to create
// {
// 	int		fd;
// 	int		stdin_tmp;
// 	char	*line;

// 	fd = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	stdin_tmp = dup(0);
// 	line = "";
// 	while (1)
// 	{
// 		write(1, "heredoc > ", 10);
// 		line = get_next_line(stdin_tmp);
// 		if (line == NULL)
// 			break ;
// 		if (strlen(delimiter) + 1 == ft_strlen(line) \
// 				&& !strncmp(line, delimiter, strlen(delimiter)))
// 		{
// 			close(stdin_tmp);
// 			break ;
// 		}
// 		else
// 			write(fd, line, strlen(line));
// 		free(line);
// 	}
// 	return (fd);
// }



void	read_heredoc(char *delimiter, int *pipe_fd, int type) // env, is_quoted
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		if (type == DLESS)
		{
			ft_putendl_fd("expanded", pipe_fd[1]); // should expanded
		}
		else if (type == NO_EX_DLESS)
		{
			ft_putendl_fd(line, pipe_fd[1]);
		}
		// if (is_quoted)
		// 	line = expand();
		free(line);
	}
}

int	get_heredoc(char *delimiter, int type) // env, is_quoted
{
	int		pipe_fds[2];

	if (pipe(pipe_fds) < 0)
	{
		write(2, "Error : pipe\n", strlen("Error : pipe\n"));
		exit(1);
	}
	read_heredoc(delimiter, pipe_fds, type); // env, is_quoted
	close(pipe_fds[1]);
	return (pipe_fds[0]);
}

void	do_redirect(t_red *red)
{
	// if (red->file_fd < 0)
	// 	exit(1);
	if (red->file_fd != -1 && red->std_target_fd != -1)
	{
		if (dup2(red->file_fd, red->std_target_fd) < 0)
			exit(1); // error dup2
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

int	open_file(t_red *reds, int is_child) // t_env *env
{
	size_t	i;

	i = 0;
	while (reds[i].type != TAIL)
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
			reds[i].file_fd = get_heredoc(reds[i].target, reds[i].type); // env, is_quoted
			reds[i].std_target_fd = 0;
		}
		else if (reds[i].type == DGREAT)
		{
			reds[i].file_fd = open(reds[i].target, \
					O_CREAT | O_WRONLY | O_APPEND, 0644);
			reds[i].std_target_fd = 1;
		}
		if (reds[i].file_fd < 0)
		{
			ft_printf_stderr("bash: %s: %s\n", reds[i].target, strerror(errno));
			while (i--)
				close(reds[i].file_fd);
			if (is_child)
				exit(1); // return するのもありかも
			else
				return (0);
		}
		i++;
	}
	return (1);
}

// void	open_all_file_in_cmds(t_red *reds)
// {
// 	size_t	i;

// 	i = 0;
// 	while (reds[i].type != TAIL)
// 	{
// 		if (reds[i].type == LESS)
// 		{
// 			reds[i].file_fd = open(reds[i].target, O_RDONLY);
// 			reds[i].std_target_fd = 0;
// 		}
// 		else if (reds[i].type == GREAT)
// 		{
// 			reds[i].file_fd = open(reds[i].target, \
// 					O_CREAT | O_RDWR | O_TRUNC, 0644);
// 			reds[i].std_target_fd = 1;
// 		}
// 		else if (reds[i].type == DLESS)
// 		{
// 			reds[i].file_fd = get_heredoc(reds[i].target);
// 			reds[i].std_target_fd = 0;
// 		}
// 		else if (reds[i].type == DGREAT)
// 		{
// 			reds[i].file_fd = open(reds[i].target, \
// 					O_CREAT | O_WRONLY | O_APPEND, 0644);
// 			reds[i].std_target_fd = 1;
// 		}
// 		i++;
// 	}
// }
