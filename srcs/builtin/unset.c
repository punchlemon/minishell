#include "builtin.h"

t_env	*search_same_key(t_env *env, char *key)
{
	while (env)
	{
		if (!strcmp(env->key, key))
			return (env);
		env = env->next;
	}
	return (NULL);
}

void	free_env_node(t_env *env)
{
	free(env->key);
	free(env->value);
	free(env);
}

void	unset_target_node(t_env **env, t_env *target)
{
	t_env	*crr;
	t_env	*prev;

	prev = NULL;
	crr = *env;
	if (crr == target)
	{
		*env = crr->next;
		free_env_node(crr);
	}
	else
	{
		while (crr)
		{
			if (crr == target)
			{
				prev->next = crr->next;
				free_env_node(crr);
				break ;
			}
			prev = crr;
			crr = crr->next;
		}
	}
}

int	builtin_unset(t_env **env, char **args)
{
	size_t	i;
	t_env	*node;

	i = 0;
	while (args[i])
	{
		node = search_same_key(*env, args[i]);
		if (node != NULL)
		{
			unset_target_node(env, node);
		}
		i++;
	}
	return (0);
}

// ほんとにunsetできているのか？
// export(引数なし)で表示するものはあっているのか
// 多分mainのenvのtopに変更があった時に変わってない // ok

// issue

// unset PWD -> export or env // ok
// 	occurs segv // ok