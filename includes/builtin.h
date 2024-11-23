/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:58:34 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/21 17:38:08 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "libft.h"
# include "minishell.h"

# include "errno.h"

// cd command
int		builtin_cd(t_env **env, char **args);
char	*search_abspath_from_relpath(char *relpath);
char	*ft_getcwd(void);
char	*search_env_return_its_value(t_env *env, char *key);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**join_target_str(char **target, char *single);
char	**back_single(char **target);
char	*make_target_path(t_env **env, char **args, int *status);
t_env	*ft_getenv(t_env *env, char *key);
t_env	*create_node(char *key, char *value);
void	add_node_to_env(t_env **env, char *key, char *value);
void	change_directory(char *path, char **args, int *status);
void	change_env_old_new(t_env **env);

// echo command
int		check_option(char *arg);
int		builtin_echo(char **args);

// env command
int		builtin_env(t_env **env, char **args);

// exit command
void	is_numeric(int argc, char **args, int status, int is_child);
void	is_not_numeric(int argc, char **arg, int is_childs);
int		check_overflow(char *str);
int		is_num(char *str);
int		count_args(char **args);
int		builtin_exit(t_env *env, char **args, int status, int is_child);

// export command
void	swap_env(t_env *crr, t_env *next);
t_env	*sort_env(t_env *top);
void	print_env(t_env *env);
void	split_into_key_value(char **line, char **key, char **value, int *flag);
void	change_value(t_env *env, char *key, char *value, int flag);
t_env	*_make_new_node(char *key, char *value);
int		set_key_value(t_env **env, char *key, char *value);
int		search_key_from_env(t_env *env, char *key);
int		export_env(t_env **env, char *line);
int		builtin_export(t_env **env, char **args);
int		is_alpha_under(char c);
int		is_alpha_num_under(char c);
int		is_valid_key(char *key);
void	malloc_error_exit(void);

// pwd command
int		builtin_pwd(void);

// unset command
t_env	*search_same_key(t_env *env, char *key);
void	free_env_node(t_env *env);
void	unset_target_node(t_env **env, t_env *target);
int		builtin_unset(t_env **env, char **args);

#endif
