#include "minishell.h"
#include "builtin.h"

char	*search_env_return_its_value(t_env *env, char *key)
{
	while (env->next != NULL)
	{
		if (strcmp(env->key, key) == 0)
			return(env->value);
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
		if (strcmp(env->key, key) != 0)
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
		write(2, "Error: getcwd\n", 14);
		exit(1);
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

char	**back_single(char **target)
{
	char	*tmp;

	tmp = *target;
	*target = strndup(*target, strrchr(*target, '/') - *target);
	free(tmp);
	if (target == NULL)
		return (NULL);
	return (target);
}

char	*search_abspath_from_relpath(char *relpath)
{
	char	*target;
	char	*single;
	size_t	i;

	target = ft_getcwd();
	while (*relpath != '\0')
	{
		i = 0;
		while (relpath[i] != '/' && relpath[i] != '\0')
			i++;
		single = ft_substr(relpath, 0, i);
		if (single == NULL)
			return (NULL);
		if (strcmp(single, "..") == 0)
		{
			if (back_single(&target) == NULL)
				return (NULL);
		}
		else if (strcmp(single, ".") != 0)
		{
			if (join_target_str(&target, single) == NULL)
				return (NULL);
		}
		free(single);
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
			write(2, "bash: cd: HOME not set\n", 23);
			*status = 1;
			return (NULL);
		}
		target_path = strdup(home_value);
	}
	else if (args[0][0] == '/')
		target_path = strdup(args[0]);
	else
		target_path = search_abspath_from_relpath(args[0]);
	if (target_path == NULL)
		malloc_error_exit();
	return (target_path);
}

t_env	*create_node(char *key, char *value) // list.c
{
	t_env	*env;

	env = calloc(1, sizeof(t_env));
	if (env == NULL)
		malloc_error_exit();
	env->key = key;
	env->value = value;
	return (env);
}

void	add_node_to_env(t_env **env, char *key, char *value) // list.c
{
	t_env	*new;
	t_env	*last;

	if (value == NULL)
	{
		new = create_node(strdup(key), NULL);
		if (new->key == NULL)
			malloc_error_exit();
	}
	else
	{
		new = create_node(strdup(key), strdup(value));
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
		save = strdup(path);
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
		{
			printf("bash: cd: %s : No such file or directory\n", args[0]);
			// return status is 1
		}
		else if (errno == EACCES)
		{
			printf("bash: cd: %s : Perimission denied\n", args[0]);
			// return status is 1
		}
		else if (errno == ENOTDIR)
		{
			printf("bash: cd: %s : Not a directory\n", args[0]);
			// return status is 1
		}
		*status = 1;
	}
	return ;
}

int	builtin_cd(t_env **env, char **args)
{
	char	*path;
	int		status;

	path = make_target_path(env, args, &status);
	if (path == NULL)
		return (status);
	change_directory(path, args, &status);
	free(path);
	change_env_old_new(env);
	return (status);
}

// issue

// search_env_return_its_value
