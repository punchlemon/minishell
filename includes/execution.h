/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:26:05 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/27 17:13:25 by hnakayam         ###   ########.fr       */
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

// get_path_cmd
char		**get_splited_path_env(t_env *env);
char		*search_binary_file(char *cmd_without_op);
char		*search_excutable_file(char *file);
char		*join_path(char *env, char *cmd);
char		*search_cmd(char *cmd_without_op, char **splited_path_envp);
char		*get_path_cmd(char *cmd, char **splited_path_envp);
void		free_two_dimensional_array(char **strs);

// execute_cmds
int			is_builtin(char *cmd);
int			destruct_forks(t_cmd *cmds, size_t len);
t_cmd		*init_cmds(t_cmd_a *cmd_a_s);
int			exe_cmds(t_cmd_a *cmd_a_s, t_env **env, int *status);

// execute_cmds
int			execute_builtin_cmd(t_env **env, t_cmd *cmd, int *status,
				int is_child);
void		excute_cmd(t_cmd *cmd, char **splited_path_env,
				t_env **env, int *status);
void		check_is_file(char *path_cmd, char *cmd);

// expand
void		delete_cmd_exe(t_cmd *cmd);
size_t		count_tkns_for_word(t_tkn *tkns);
void		count_cmd(size_t *words_len, size_t *reds_len, t_tkn *tkns);
int			ft_is_charactor(char c);
size_t		charactors_len(const char *src);
size_t		check_valiable(const char *src);
char		*get_value(const char *src, t_env *env, char *st);
void		count_word_in_a_tkn(t_tkn *tkn, size_t *word_len, t_env *env,
				char *st);
size_t		count_word(t_tkn *tkns, t_env *env, char *st);
void		store_word_in_a_tkn(char *dst, t_tkn *tkn, t_env *env, char *st);
void		store_word(char *dst, t_tkn *tkns, t_env *env, char *st);
int			create_word(char **pp, t_tkn *tkns, t_env *env, char *st);
int			is_env_variable(const char *head, const char *tail);
size_t		count_heredoc(t_tkn *tkns, size_t t_len);
size_t		store_heredoc(t_red *red, t_tkn *tkns, size_t t_len);
int			create_heredoc(t_red *red, t_tkn *tkns);
int			store_cmd(t_cmd *cmd, t_tkn *tkns, t_env *env, char *st);
t_cmd		*expand_cmd(t_cmd *cmd, t_tkn *tkns, t_env *env, int status);

// execute_utils
size_t		count_env_len(t_env *env);
char		**env_to_environ(t_env *env);

// pipe
int			prepare_pipe(t_cmd *cmd);
void		prepare_pipe_in_child(t_cmd *cmd);
void		prepare_pipe_in_parent(t_cmd *cmd);

// heredoc
int			get_heredoc(char *delimiter, int is_child, int *status);
int			get_heredoc_expand(char *delimiter, int is_child, t_env *env,
				int *status);
void		count_expand_heredoc(size_t *word_len, const char *line, t_env *env,
				char *st);
void		store_expand_heredoc(char **expanded, const char *line, t_env *env,
				char *st);
void		read_heredoc(char *delimiter, int *pipe_fd, int *status);
void		read_heredoc_expand(char *delimiter, int *pipe_fd, t_env *env,
				int *status);
char		*expand_heredoc(const char *line, t_env *env, int *status);

// redirect
void		do_redirect(t_red *red);
void		set_redirects(t_red *reds);
int			is_ambiguous_dir(t_red *reds, int i, int is_child);
int			cause_error_open_file(t_red *reds, size_t i, int is_child,
				int *status);
void		open_file(t_red *reds, int is_child, t_env *env, int *status);
int			open_all_file(t_red *reds, int is_child, t_env *env, int *status);

// itoa // for test
char		*reverse(char *temp);
void		minus(int *sign, int *n);
char		*check1_zero_intmin(int n);
char		*ft_itoa(int n);

// expand
size_t		check_valiable(const char *src);
char		*get_value(const char *src, t_env *env, char *st);

#endif
