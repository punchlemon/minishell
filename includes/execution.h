/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:26:05 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/24 17:35:35 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "libft.h"
# include "minishell.h"
/// 今後はlibftを本格的に導入していく。その暁には#include "minishell.h"を削除する
/// 笑笑

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>

typedef struct s_num
{
	int	pipe_in[2];
	int	pipe_out[2];
}	t_num;

// exe
char		**get_splited_path_env(t_env *env);
char		*search_binary_file(char *cmd_without_op);
char		*search_excutable_file(char *file);
char		*join_path(char *env, char *cmd);
char		*search_cmd(char *cmd_without_op, char **splited_path_envp);
char		*get_path_cmd(char *cmd, char **splited_path_envp);
void		free_two_dimensional_array(char **strs);

// excute
void		excute_cmd(t_cmd *cmd, char **splited_path_env,
				t_env **env, int status);
int			exe_cmds(t_cmd_a *cmd_a_s, t_env **env, int *status);
int			execute_builtin_cmd(t_env **env, t_cmd *cmd, int status,
				int is_child);
int			is_builtin(char *cmd);

// init
// void		init_conds(t_cond *conds);

// pipe
int			prepare_pipe(t_cmd *cmd);
void		prepare_pipe_in_child(t_cmd *cmd);
void		prepare_pipe_in_parent(t_cmd *cmd);

// heredoc
int			get_heredoc(char *delimiter);
int			get_heredoc_expand(char *delimiter, t_env *env, char *st);
void		count_expand_heredoc(size_t *word_len, const char *line, t_env *env,
				char *st);
void		store_expand_heredoc(char **expanded, const char *line, t_env *env,
				char *st);
void		read_heredoc(char *delimiter, int *pipe_fd);
void		read_heredoc_expand(char *delimiter, int *pipe_fd, t_env *env,
				char *st);
char		*expand_heredoc(const char *line, t_env *env, char *st);

// redirect
int			get_heredoc(char *delimiter);
void		do_redirect(t_red *red);
void		set_redirects(t_red *reds);
int			open_all_file(t_red *reds, int is_child, t_env *env, char *st);

// itoa // for test
char		*reverse(char *temp);
void		minus(int *sign, int *n);
char		*check1_zero_intmin(int n);
char		*ft_itoa(int n);

// expand
size_t		check_valiable(const char *src);
char		*get_value(const char *src, t_env *env, char *st);

#endif
