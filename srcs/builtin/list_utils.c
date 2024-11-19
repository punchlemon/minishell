#include "minishell.h"
// #include "env_list.h"

void	set_env(t_env *env, char *key, char *value)
{
	while (env != NULL)
	{
		if (strcmp(env->key, key) == 0)
		{
			if (env->value == NULL)
				return ;
			free(env->value);
			env->value = strdup(value);
			return ;
		}
		env = env->next;
	}
}

void	free_list(t_env *top)
{
	t_env	*tmp;

	while (top != NULL)
	{
		free(top->key);
		free(top->value);
		tmp = top->next;
		free(top);
		top = tmp;
	}
}
