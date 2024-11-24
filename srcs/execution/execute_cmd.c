/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:35:14 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/24 18:45:39 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "sig.h"
#include "ft_printf.h"
#include "ft_printf_stderr.h"
#include "libft.h"
#include "builtin.h"

void	check_is_file(char *path_cmd, char *cmd)
{
	struct stat		st;

	if (strcmp(cmd, "") == 0)
	{
		ft_printf_stderr("Command '' not found\n");
		exit(127);
	}
	if (stat(path_cmd, &st) < 0)
	{
		perror("stat");
		exit(1);
	}
	if (st.st_mode & S_IFDIR && !(st.st_mode & S_IFREG))
	{
		ft_printf_stderr("minishell: %s: Is a directory\n", cmd);
		exit(126);
	}
}

void	excute_cmd(t_cmd *cmd, char **splited_path_env, t_env **env, int status)
{
	char	*path_cmd;
	char	**environ;
	char	*st;

	set_exec_child_handler();
	prepare_pipe_in_child(cmd);
	st = ft_itoa(status);
	if (!st)
		exit(1);
	if (!open_all_file(cmd->reds, 1, *env, st))
		exit(1);
	free(st);
	if (cmd->reds != NULL)
		set_redirects(cmd->reds);
	if (cmd->words[0] == NULL)
		exit(0);
	path_cmd = get_path_cmd(cmd->words[0], splited_path_env);
	check_is_file(path_cmd, cmd->words[0]);
	environ = env_to_environ(*env);
	if (environ == NULL)
		exit(1);
	execve(path_cmd, cmd->words, environ);
	ft_printf_stderr("Error : execve\n");
	exit(1);
}

int	execute_builtin_cmd(t_env **env, t_cmd *cmd, int status, int is_child)
{
	char	*command_name;
	char	**args;
	char	*st;

	if (is_child)
		prepare_pipe_in_child(cmd);
	st = ft_itoa(status);
	if (!st)
		exit(1);
	if (!open_all_file(cmd->reds, is_child, *env, st))
		return (1); // 1 ではない気がする
	free(st);
	if (cmd->reds != NULL)
		set_redirects(cmd->reds);
	command_name = cmd->words[0];
	args = &cmd->words[1];
	if (strcmp(command_name, "cd") == 0)
		return (builtin_cd(env, args));
	else if (strcmp(command_name, "pwd") == 0)
		return (builtin_pwd());
	else if (strcmp(command_name, "echo") == 0)
		return (builtin_echo(args));
	else if (strcmp(command_name, "env") == 0)
		return (builtin_env(env, args));
	else if (strcmp(command_name, "exit") == 0)
		return (builtin_exit(*env, args, status, is_child));
	else if (strcmp(command_name, "export") == 0)
		return (builtin_export(env, args));
	else if (strcmp(command_name, "unset") == 0)
		return (builtin_unset(env, args));
	return (1);
}
