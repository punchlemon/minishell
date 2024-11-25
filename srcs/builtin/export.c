/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:23:05 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/25 17:01:46 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"

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

	key_end = ft_strchr(*line, '=');
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
		if (ft_strcmp(env->key, key) == 0)
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
