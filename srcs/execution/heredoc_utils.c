/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:50:24 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/25 21:07:46 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "ft_printf_stderr.h"
#include "libft.h"

void	count_expand_heredoc(size_t *word_len, const char *line, t_env *env,
	char *st)
{
	size_t	l_i;
	size_t	sub;
	char	*tmp;

	*word_len = ft_strlen(line);
	l_i = 0;
	while (line[l_i])
	{
		sub = check_valiable(&line[l_i]);
		if (sub)
		{
			tmp = get_value(&line[l_i], env, st);
			if (tmp)
				*word_len += ft_strlen(tmp);
			*word_len -= sub;
			l_i += sub;
		}
		else
			l_i++;
	}
}

void	store_expand_heredoc(char **expanded, const char *line, t_env *env,
	char *st)
{
	size_t	l_i;
	size_t	e_i;
	size_t	sub;
	char	*tmp;

	l_i = 0;
	e_i = 0;
	while (line[l_i])
	{
		sub = check_valiable(&line[l_i]);
		if (sub)
		{
			tmp = get_value(&line[l_i], env, st);
			if (tmp)
			{
				ft_memmove(&(*expanded)[e_i], tmp, ft_strlen(tmp));
				e_i += ft_strlen(tmp);
			}
			l_i += sub;
		}
		else
			(*expanded)[e_i++] = line[l_i++];
	}
}

void	read_heredoc(char *delimiter, int *pipe_fd)
{
	char	*line;
	size_t	i;

	i = 0;
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
		{
			ft_printf_stderr("minishell: warning: here-document at line %d", i);
			ft_printf_stderr(" delimited by end-of-file");
			ft_printf_stderr(" (wanted `%s')\n", delimiter);
			break ;
		}
		if (ft_strcmp(line, delimiter) == 0)
			return (free(line), (void)0);
		ft_putendl_fd(line, pipe_fd[1]);
		free(line);
		i++;
	}
}

void	read_heredoc_expand(char *delimiter, int *pipe_fd, t_env *env, char *st)
{
	char	*line;
	char	*expanded;
	size_t	i;

	i = 0;
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
		{
			ft_printf_stderr("minishell: warning: here-document delimited by");
			ft_printf_stderr(" end-of-file (wanted `%s')\n", delimiter);
			break ;
		}
		if (ft_strcmp(line, delimiter) == 0)
			return (free(line), (void)0);
		expanded = expand_heredoc(line, env, st);
		ft_putendl_fd(expanded, pipe_fd[1]);
		free(expanded);
		free(line);
		i++;
	}
}

char	*expand_heredoc(const char *line, t_env *env, char *st)
{
	char	*expanded;
	size_t	len;

	count_expand_heredoc(&len, line, env, st);
	expanded = ft_xcalloc(sizeof(char) * (len + 1));
	if (!expanded)
		exit(1);
	expanded[len] = '\0';
	store_expand_heredoc(&expanded, line, env, st);
	return (expanded);
}
