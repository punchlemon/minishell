/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:27:46 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/25 16:44:35 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include "ft_printf_stderr.h"

t_env	*create_node(char *key, char *value)
{
	t_env	*env;

	env = ft_xcalloc(sizeof(t_env));
	if (env == NULL)
		malloc_error_exit();
	env->key = key;
	env->value = value;
	return (env);
}

void	add_node_to_env(t_env **env, char *key, char *value)
{
	t_env	*new;
	t_env	*last;

	if (value == NULL)
	{
		new = create_node(ft_strdup(key), NULL);
		if (new->key == NULL)
			malloc_error_exit();
	}
	else
	{
		new = create_node(ft_strdup(key), ft_strdup(value));
		if (new->key == NULL || new->value == NULL)
			malloc_error_exit();
	}
	if (*env == NULL)
		*env = new;
	else
	{
		last = *env;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

void	change_env_old_new(t_env **env)
{
	char	*cwd;
	char	*path;
	char	*save;

	path = search_env_return_its_value(*env, "PWD");
	if (path == NULL)
		save = NULL;
	else
	{
		save = ft_strdup(path);
		if (save == NULL)
			malloc_error_exit();
	}
	cwd = ft_getcwd();
	set_env(*env, "PWD", cwd);
	if (ft_getenv(*env, "OLDPWD") == NULL)
		add_node_to_env(env, "OLDPWD", save);
	else
		set_env(*env, "OLDPWD", save);
	free(cwd);
	free(save);
}

void	change_directory(char *path, char **args, int *status)
{
	if (chdir(path) < 0)
	{
		if (errno == ENOENT)
			ft_printf_stderr("minishell: cd: %s : No such file or directory\n",
				args[0]);
		else if (errno == EACCES)
			ft_printf_stderr("minishell: cd: %s : Perimission denied\n",
				args[0]);
		else if (errno == ENOTDIR)
			ft_printf_stderr("minishell: cd: %s : Not a directory\n", args[0]);
		*status = 1;
	}
	return ;
}

int	builtin_cd(t_env **env, char **args)
{
	char	*path;
	int		status;
	int		argc;

	status = 0;
	argc = count_args(args);
	if (argc > 1)
	{
		ft_printf_stderr("minishell: cd: too many arguments\n");
		return (1);
	}
	path = make_target_path(env, args, &status);
	if (path == NULL)
		return (status);
	change_directory(path, args, &status);
	free(path);
	change_env_old_new(env);
	return (status);
}
