/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:30:54 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/24 16:22:17 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include "ft_printf_stderr.h"

char	**back_single(char **target)
{
	size_t	len;
	char	*tmp;

	tmp = *target;
	len = strrchr(*target, '/') - *target;
	if (len != 0)
	{
		*target = strndup(*target, len);
		free(tmp);
		if (target == NULL)
			return (NULL);
	}
	else
	{
		free(tmp);
		*target = strdup("/");
	}
	return (target);
}

int	search_abspath_from_relpath_2(char *relpath, char **target, size_t i)
{
	char	*single;

	single = ft_substr(relpath, 0, i);
	if (single == NULL)
		return (0);
	if (strcmp(single, "..") == 0)
	{
		if (back_single(target) == NULL)
			return (0);
	}
	else if (strcmp(single, ".") != 0)
	{
		if (join_target_str(target, single) == NULL)
			return (0);
	}
	free(single);
	return (1);
}

char	*search_abspath_from_relpath(char *relpath)
{
	char	*target;
	size_t	i;

	target = ft_getcwd();
	while (*relpath != '\0' && target != NULL)
	{
		i = 0;
		while (relpath[i] != '/' && relpath[i] != '\0')
			i++;
		if (search_abspath_from_relpath_2(relpath, &target, i) != 1)
			return (NULL);
		if (relpath[i] == '\0')
			break ;
		relpath += i + 1;
	}
	return (target);
}

char	*make_target_path(t_env **env, char **args, int *status)
{
	char	*target_path;
	char	*home_value;

	if (args[0] == NULL)
	{
		home_value = search_env_return_its_value(*env, "HOME");
		if (home_value == NULL)
		{
			ft_printf_stderr("minishell: cd: HOME not set\n");
			*status = 1;
			return (NULL);
		}
		target_path = strdup(home_value);
	}
	else if (args[0][0] == '/')
		target_path = strdup(args[0]);
	else
		target_path = search_abspath_from_relpath(args[0]);
	ft_printf_stderr("target path = %s\n", target_path);
	return (target_path);
}
