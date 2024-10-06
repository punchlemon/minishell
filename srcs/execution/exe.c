/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:37:47 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/06 18:46:01 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"

void	delete_pp(char **src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		free(src[i]);
		i++;
	}
	free(src);
}

char	**get_env(void)
{
	char	*path_env;

	path_env = getenv("PATH");
	if (path_env == NULL)
		exit(1);
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
	// if (info->splited_path_envp == NULL)
	// 	error_no_envp(info, cmd_without_op);
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
			free(cmd_without_op);
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
	// cmd_without_op = ft_strndup(cmd);
	// if (cmd == NULL)
	// 	exit(1);
	path_cmd = search_cmd(cmd, splited_path_envp);
	if (path_cmd == NULL)
	{
		printf("%s: command not found\n", cmd);
		free(cmd);
		exit(127);
	}
	free(cmd);
	return (path_cmd);
}

void	exec_child(char **srcs, char **splited_path_envp, char **environ)
{
	char	*path_cmd;

	path_cmd = get_path_cmd(srcs[0], splited_path_envp);
	execve(path_cmd, srcs, environ);
}

void	free_two_dimention_array(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	exe(char **srcs, char **environ, int *status)
{
	char	**splited_path_envp;
	pid_t	child;

	splited_path_envp = get_env();
	if (splited_path_envp == NULL)
		exit(1);
	child = fork();
	if (child == -1)
		exit(1);
	else if (child == 0)
		exec_child(srcs, splited_path_envp, environ);
	waitpid(child, status, 0);
	free_two_dimention_array(splited_path_envp);
	delete_pp(srcs);
	if (WIFEXITED(*status))
		WEXITSTATUS(*status);
}
