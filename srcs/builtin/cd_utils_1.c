/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:29:55 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/25 16:40:45 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include "ft_printf_stderr.h"

char	*search_env_return_its_value(t_env *env, char *key)
{
	while (env != NULL)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

t_env	*ft_getenv(t_env *env, char *key)
{
	if (key == NULL)
		return (NULL);
	while (env != NULL)
	{
		if (ft_strcmp(env->key, key) != 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

char	*ft_getcwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		if (errno == ENOENT || errno == ENOTDIR || errno == EACCES)
		{
			ft_printf_stderr("cd: cannot get current working directory\n");
			return (NULL);
		}
		ft_printf_stderr("Error: getcwd\n");
		return (NULL);
	}
	return (cwd);
}

char	**join_target_str(char **target, char *single)
{
	char	*tmp;

	tmp = *target;
	*target = ft_strjoin(*target, "/");
	free(tmp);
	if (target == NULL)
		return (NULL);
	tmp = *target;
	*target = ft_strjoin(*target, single);
	free(tmp);
	if (target == NULL)
		return (NULL);
	return (target);
}
