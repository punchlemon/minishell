#include "env.h"

int	builtin_env(t_env **env, char **args)
{
	t_env	*top;

	top = *env;
	if (args[0] != NULL)
	{
		write(2, "Syntax Error\n", 13);
		return (1);
	}
	while (top)
	{
		printf("%s=%s\n", top->key, top->value);
		top = top->next;
	}
	return (0);
}
