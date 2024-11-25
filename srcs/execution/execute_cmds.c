/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:35:03 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/25 16:42:16 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "sig.h"
#include "ft_printf.h"
#include "ft_printf_stderr.h"
#include "libft.h"
#include "builtin.h"

int	is_builtin(char *cmd)
{
	if (cmd == NULL)
		return (0);
	if (ft_strcmp(cmd, "cd") == 0 || ft_strcmp(cmd, "echo") == 0 || \
		ft_strcmp(cmd, "env") == 0 || ft_strcmp(cmd, "exit") == 0 || \
		ft_strcmp(cmd, "export") == 0 || ft_strcmp(cmd, "pwd") == 0 || \
		ft_strcmp(cmd, "unset") == 0)
	{
		return (1);
	}
	return (0);
}

int	destruct_forks(t_cmd *cmds, size_t len)
{
	size_t	i;
	int		status;
	int		return_status;

	i = 0;
	status = 0;
	return_status = 0;
	while (i < len)
	{
		waitpid(cmds[i].pid, &status, 0);
		if (WIFSIGNALED(status))
		{
			return_status = WTERMSIG(status) + 128;
			if (return_status == 130)
				ft_printf_stderr("\n");
		}
		if (WIFEXITED(status))
			return_status = WEXITSTATUS(status);
		i++;
	}
	return (return_status);
}

t_cmd	*init_cmds(t_cmd_a *cmd_a_s)
{
	t_cmd	*cmds;
	size_t	len;

	len = 0;
	while (cmd_a_s[len].tkns)
		len++;
	cmds = ft_xcalloc(sizeof(t_cmd) * (len + 1));
	cmds[len].type = TAIL;
	while (len--)
	{
		cmds[len].type = NORMAL;
		cmds[len].pipe_in[0] = 0;
		cmds[len].pipe_in[1] = -1;
		cmds[len].pipe_out[0] = -1;
		cmds[len].pipe_out[1] = 1;
		cmds[len].pid = 0;
	}
	return (cmds);
}

int	_execute_cmd(t_cmd *cmd, t_env **env, int status, char **splited_path_env)
{
	cmd->pid = fork();
	if (cmd->pid < 0)
	{
		ft_printf_stderr("Error: %s: %s\n", "fork", strerror(errno));
		return (0);
	}
	else if (cmd->pid == 0 && is_builtin(cmd->words[0]))
		exit(execute_builtin_cmd(env, cmd, status, 1));
	else if (cmd->pid == 0)
		excute_cmd(cmd, splited_path_env, env, status);
	set_exec_handler(true);
	prepare_pipe_in_parent(cmd);
	return (1);
}

int	exe_cmds(t_cmd_a *cmd_a_s, t_env **env, int *st_p)
{
	size_t	i;
	char	**s_path_env;
	t_cmd	*cmds;

	s_path_env = get_splited_path_env(*env);
	cmds = init_cmds(cmd_a_s);
	i = 0;
	while (cmds[i].type != TAIL)
	{
		if (prepare_pipe(&cmds[i]))
			break ;
		if (!expand_cmd(&cmds[i], cmd_a_s[i].tkns, *env, *st_p))
			return (0);
		if (is_builtin(cmds[i].words[0]) && i == 0 && cmds[i + 1].type == TAIL)
			return (execute_builtin_in_parent(cmds, env, st_p, s_path_env));
		if (!_execute_cmd(&cmds[i], env, *st_p, s_path_env))
			break ;
		i++;
	}
	*st_p = destruct_forks(cmds, i);
	free_two_dimensional_array(s_path_env);
	delete_cmd_exe(cmds);
	free(cmds);
	return (*st_p);
}