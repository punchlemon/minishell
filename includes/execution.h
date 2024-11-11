/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:26:05 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/11 17:21:50 by hnakayam         ###   ########.fr       */
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
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>

// execution
void		exe(char **srcs, char **environ, int *status);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*get_path_cmd(char *cmd, char **splited_path_envp);
void		free_two_dimention_array(char **strs);
char		**get_env(void);

// excute
void		excute_cmd(t_cmd *cmd, char **splited_path_env, char **environ);
void		exe_cmds(t_cmd *cmds, char **environ, int *status);

// init
void		init_conds(t_cond *conds);

// pipe
void		prepare_pipe(t_cmd *cmd);
void		prepare_pipe_in_child(t_cmd *cmd);
void		prepare_pipe_in_parent(t_cmd *cmd);

// redirect
int			get_heredoc(char *delimiter);
void		do_redirect(t_red *red);
void		set_redirects(t_red *reds);
void		open_all_file_in_cmds(t_red *reds);

// error
int		operation_error(char *str);

// itoa // for test
char	*reverse(char *temp);
void	minus(int *sign, int *n);
char	*check1_zero_intmin(int n);
char	*ft_itoa(int n);

#endif
