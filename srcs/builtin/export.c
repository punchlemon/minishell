#include "minishell.h"
#include "builtin.h"

void	swap_env(t_env *crr, t_env *next)
{
	char	*tmp_key;
	char	*tmp_value;

	tmp_key = crr->key;
	tmp_value = crr->value;
	crr->key = next->key;
	crr->value = next->value;
	next->key = tmp_key;
	next->value = tmp_value;
}

t_env	*sort_env(t_env *env)
{
	t_env	*crr;
	t_env	*next;

	crr = env;
	if (crr == NULL)
		return (NULL);
	while (crr != NULL)
	{
		next = crr->next;
		while (next != NULL)
		{
			if (strcmp(crr->key, next->key) > 0)
			{
				swap_env(crr, next);
			}
			next = next->next;
		}
		crr = crr->next;
	}
	return (env);
}

void	print_env(t_env *env)
{
	t_env	*sorted_env;

	sorted_env = sort_env(env);
	while (sorted_env != NULL)
	{
		ft_printf("declare -x ");
		if (sorted_env->value)
			ft_printf("%s=\"%s\"\n", sorted_env->key, sorted_env->value);
		else
			ft_printf("%s\n", sorted_env->key);
		sorted_env = sorted_env->next;
	}
}

void	split_into_key_value(char **line, char **key, char **value, int *flag)
{
	char	*key_end;

	key_end = strchr(*line, '=');
	*flag = 0;
	if (key_end == NULL)
	{
		*key = ft_strdup(*line);
		if (*key == NULL)
			malloc_error_exit();
		*value = NULL;
	}
	else
	{
		if (*(key_end - 1) == '+')
			*flag = 1;
		*key = ft_substr(*line, 0, (size_t)((key_end - *flag) - *line));
		*value = ft_strdup(key_end + 1);
		if (*key == NULL || *value == NULL)
			malloc_error_exit();
	}
}

void	change_value(t_env *env, char *key, char *value, int flag)
{
	char	*tmp;

	while (env)
	{
		if (strcmp(env->key, key) == 0)
			break ;
		env = env->next;
	}
	free(key);
	if (flag)
	{
		tmp = ft_strjoin(env->value, value);
		free(env->value);
		free(value);
		env->value = tmp;
	}
	else
	{
		free(env->value);
		env->value = value;
	}
}

t_env	*_make_new_node(char *key, char *value)
{
	t_env	*new;

	new = calloc(1, sizeof(t_env));
	if (new == NULL)
		return (NULL);
	new->key = key;
	new->value = value;
	return (new);
}

int	set_key_value(t_env **env, char *key, char *value)
{
	t_env	*new;
	t_env	*last;

	if (!is_valid_key(key))
	{
		write(2, "Invalid key\n", 12);
		return (1);
	}
	new = _make_new_node(key, value);
	if (new == NULL)
		malloc_error_exit();
	last = *env;
	if (last == NULL)
		*env = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return (0);
}

int	search_key_from_env(t_env *env, char *key)
{
	while (env)
	{
		if (!strcmp(env->key, key))
			return (1);
		env = env->next;
	}
	return (0);
}

int	export_env(t_env **env, char *line)
{
	char	*key;
	char	*value;
	int		flag;

	split_into_key_value(&line, &key, &value, &flag);
	if (search_key_from_env(*env, key))
		change_value(*env, key, value, flag);
	else
	{
		if (set_key_value(env, key, value))
			return (1);
	}
	return (0);
}

int	builtin_export(t_env **env, char **args)
{
	int		argc;
	size_t	i;
	int		status;

	status = 0;
	argc = count_args(args);
	if (argc == 0)
		print_env(*env);
	else
	{
		i = 0;
		while (args[i])
		{
			if (export_env(env, args[i]))
				status = 1;
			i++;
		}
	}
	return (status);
}
