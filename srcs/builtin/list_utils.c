/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:22:44 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/25 16:41:38 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env(t_env *env, char *key, char *value)
{
	while (env != NULL)
	{
		if (ft_strcmp(env->key, key) == 0)
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
