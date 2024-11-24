/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:47:31 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/24 17:47:32 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "builtin.h"
#include "ft_printf_stderr.h"

char	*search_excutable_file(char *file)
{
	if (strncmp(file, "./", 2) == 0 || strncmp(file, "/", 1) == 0)
	{
		if (!access(file, F_OK))
		{
			if (!access(file, X_OK))
			{
				return (file);
			}
			ft_printf_stderr("minishell: %s: %s\n", file, strerror(errno));
			exit(126);
		}
		else
		{
			ft_printf_stderr("minishell: %s: %s\n", file, strerror(errno));
			exit(127);
		}
	}
	return (NULL);
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
			ft_printf_stderr("minishell: %s: %s\n", path_cmd, strerror(errno));
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
	path_cmd = search_cmd(cmd, splited_path_envp);
	if (path_cmd == NULL)
	{
		ft_printf_stderr("%s: command not found\n", cmd);
		free(cmd);
		exit(127);
	}
	return (path_cmd);
}
