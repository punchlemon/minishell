/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:35:14 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/29 19:12:19 by hnakayam         ###   ########.fr       */
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

	if (ft_strcmp(cmd, "") == 0)
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

void	excute_cmd(t_cmd *cmd, char **splited_path_env, t_env **env,
	int *status)
{
	char	*path_cmd;
	char	**environ;

	set_exec_child_handler();
	prepare_pipe_in_child(cmd);
	if (!open_all_file(cmd->reds, 1, status))
		exit(1);
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

int	execute_builtin_in_parent(t_cmd *cmds, t_env **env, int *status,
	char **splited_path_env)
{
	int	tmp_in;
	int	tmp_out;

	tmp_in = 0;
	tmp_out = 0;
	if (ft_strcmp(cmds[0].words[0], "exit") != 0)
	{
		tmp_in = dup(0);
		tmp_out = dup(1);
	}
	*status = execute_builtin_cmd(env, &cmds[0], status, 0);
	free_two_dimensional_array(splited_path_env);
	delete_cmd_exe(cmds);
	free(cmds);
	dup2(tmp_in, 0);
	dup2(tmp_out, 1);
	close(tmp_in);
	close(tmp_out);
	return (*status);
}

int	execute_builtin_cmd(t_env **env, t_cmd *cmd, int *status, int is_child)
{
	char	*command_name;

	if (is_child)
		prepare_pipe_in_child(cmd);
	if (!open_all_file(cmd->reds, is_child, status))
		return (*status);
	if (cmd->reds != NULL)
		set_redirects(cmd->reds);
	command_name = cmd->words[0];
	if (ft_strcmp(command_name, "cd") == 0)
		return (builtin_cd(env, &cmd->words[1]));
	else if (ft_strcmp(command_name, "pwd") == 0)
		return (builtin_pwd());
	else if (ft_strcmp(command_name, "echo") == 0)
		return (builtin_echo(&cmd->words[1]));
	else if (ft_strcmp(command_name, "env") == 0)
		return (builtin_env(env, &cmd->words[1]));
	else if (ft_strcmp(command_name, "exit") == 0)
		return (builtin_exit(*env, &cmd->words[1], *status, is_child));
	else if (ft_strcmp(command_name, "export") == 0)
		return (builtin_export(env, &cmd->words[1]));
	else if (ft_strcmp(command_name, "unset") == 0)
		return (builtin_unset(env, &cmd->words[1]));
	return (1);
}
