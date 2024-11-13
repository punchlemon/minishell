#ifndef UNSET_H
# define UNSET_H

# include "list.h"

t_env	*search_same_key(t_env *env, char *key);
void	free_env_node(t_env *env);
void	unset_target_node(t_env **env, t_env *target);
int		builtin_unset(t_env **env, char **args);

#endif