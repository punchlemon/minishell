#ifndef CD_H
# define CD_H

# include "errno.h"

int		builtin_cd(t_env **env, char **args);
char	*search_abspath_from_relpath(char *relpath);
char	*ft_getcwd(void);
char	*search_env_return_its_value(t_env *env, char *key);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**join_target_str(char **target, char *single);
char	**back_single(char **target, char *single);
char	*make_target_path(t_env **env, char **args, int *status);
t_env	*ft_getenv(t_env *env, char *key);
t_env	*create_node(char *key, char *value);
void	add_node_to_env(t_env **env, char *key, char *value);
void	change_directory(char *path, char **args, int *status);
void	change_env_old_new(t_env **env);

// ft_getenv, create_node, add_node_to_env better be list.c

#endif
