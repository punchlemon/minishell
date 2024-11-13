#ifndef EXPORT_H
# define EXPORT_H

# include "list.h"

void	swap_env(t_env *crr, t_env *next);
t_env	*sort_env(t_env *top);
void	print_env(t_env *env);
void	split_into_key_value(char **line, char **key, char **key_end, char **value);
void	change_value(t_env *env, char *key, char *value);
t_env	*_make_new_node(char *key, char *value);
int		set_key_value(t_env **env, char *key, char *value);
int		search_key_from_env(t_env *env, char *key);
int		export_env(t_env **env, char *line);
int		builtin_export(t_env **env, char **args);
int		is_alpha_under(char c);
int		is_alpha_num_under(char c);
int		is_valid_key(char *key);
void	malloc_error_exit(void);

#endif