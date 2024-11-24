/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:31:23 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/24 16:33:53 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"

t_env	*_make_new_node(char *key, char *value)
{
	t_env	*new;

	new = ft_xcalloc(sizeof(t_env));
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
		ft_printf_stderr("minishell: export: %s: not a valid identifier\n");
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
