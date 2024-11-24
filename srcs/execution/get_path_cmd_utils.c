/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_cmd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:42:27 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/24 17:45:13 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "builtin.h"
#include "ft_printf_stderr.h"

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

char	**get_env(t_env *env)
{
	char	*path_env;

	path_env = search_env_return_its_value(env, "PATH");
	if (path_env == NULL)
		return (NULL);
	return (ft_split(path_env, ':'));
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
				ft_printf_stderr("Error: %s: %s\n", "malloc", strerror(errno));
			return (binary_file);
		}
		ft_printf_stderr("minishell: %s: %s\n", cmd_without_op, strerror(errno));
		free(cmd_without_op);
		exit(126);
	}
	ft_printf_stderr("minishell: %s: No such file of directory\n",
		cmd_without_op);
	free(cmd_without_op);
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
