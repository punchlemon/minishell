/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:37:47 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/17 20:02:34 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "builtin.h"

char	**get_env(t_env *env)
{
	char	*path_env;

	path_env = search_env_return_its_value(env, "PATH");
	if (path_env == NULL)
		return (NULL);
	return (ft_split(path_env, ':'));
}

char	*search_excutable_file(char *file)
{
	if (ft_strchr(file, '.') || ft_strchr(file, '/'))
	{
		if (!access(file, F_OK))
		{
			if (!access(file, X_OK))
			{
				return (file);
			}
			printf("bash: %s: %s\n", file, strerror(errno));
			exit(126);
		}
		else
		{
			printf("bash: %s: %s\n", file, strerror(errno));
			exit(127);
		}
	}
	return (NULL);
}

char	*search_binary_file(char *cmd_without_op)
{
	char	*binary_file;

	if (!access(cmd_without_op, F_OK))
	{
		if (!access(cmd_without_op, X_OK))
		{
			binary_file = strdup(cmd_without_op);
			if (binary_file == NULL)
				operation_error("malloc");
			return (binary_file);
		}
		printf("bash: %s: %s\n", cmd_without_op, strerror(errno));
		free(cmd_without_op); // can be double free ?
		exit(126); // anything to free ?
	}
	printf("bash: %s: No such file of directory\n", cmd_without_op);
	free(cmd_without_op); // can be double free ?
	exit(127);
	return (NULL);
}

char	*join_path(char *env, char *cmd)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(env, "/");
	if (tmp == NULL)
		exit(1);
	res = ft_strjoin(tmp, cmd);
	free(tmp);
	if (res == NULL)
		exit(1);
	return (res);
}

char	*search_cmd(char *cmd_without_op, char **splited_path_envp)
{
	char	*path_cmd;
	int		i;

	i = 0;
	if (splited_path_envp == NULL)
		return (search_binary_file(cmd_without_op));
	while (splited_path_envp[i] != NULL)
	{
		path_cmd = join_path(splited_path_envp[i], cmd_without_op);
		if (!access(path_cmd, F_OK))
		{
			if (!access(path_cmd, X_OK))
			{
				return (path_cmd);
			}
			printf("bash: %s: %s\n", path_cmd, strerror(errno));
			free(cmd_without_op); // can be double free ?
			free(path_cmd);
			exit(126);
		}
		free(path_cmd);
		i++;
	}
	return (NULL);
}

char	*get_path_cmd(char *cmd, char **splited_path_envp)
{
	char	*path_cmd;

	if (search_excutable_file(cmd))
		return (cmd);
	path_cmd = search_cmd(cmd, splited_path_envp);
	if (path_cmd == NULL)
	{
		printf("%s: command not found\n", cmd);
		free(cmd); // can be double free ?
		exit(127);
	}
	// free(cmd);
	return (path_cmd);
}

void	free_two_dimention_array(char **strs)
{
	int	i;

	i = 0;
	if (strs != NULL)
	{
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
}
