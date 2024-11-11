#include "minishell.h"
#include "ft_printf.h"
#include "libft.h"

void	excute_cmd(t_cmd *cmd, char **splited_path_env, char **environ)
{
	char	*path_cmd;

	prepare_pipe_in_child(cmd);
	if (cmd->reds != NULL)
		set_redirects(cmd->reds);
	path_cmd = get_path_cmd(cmd->words[0], splited_path_env);
	execve(path_cmd, cmd->words, environ);
	write(2, "Error : execve\n", strlen("Error : execve\n"));
	exit(1);
}

void	exe_cmds(t_cmd *cmds, char **environ, int *status)
{
	size_t	i;
	pid_t	pid;
	int		tmp_in;
	int		tmp_out;
	char	**splited_path_env;

	i = 0;
	splited_path_env = get_env();
	while (cmds[i].type != TAIL)
	{
		open_all_file_in_cmds(cmds[i].reds);
		i++;
	}
	i = 0;
	while (cmds[i].type != TAIL)
	{
		tmp_in = dup(0); // test
		tmp_out = dup(1); // test
		if (prepare_pipe(&cmds[i]))
			break ;
		pid = fork();
		if (pid < 0)
			exit(1); // error fork
		if (pid == 0)
		{
			excute_cmd(&cmds[i], splited_path_env, environ);
		}
		else
		{
			prepare_pipe_in_parent(&cmds[i]);
		}
		waitpid(pid, status, 0);
		dup2(tmp_in, 0);
		dup2(tmp_out, 1);
		close(tmp_in);
		close(tmp_out);
		if (WIFEXITED(*status))
			WEXITSTATUS(*status);
		i++;
	}
	free_two_dimention_array(splited_path_env);
}
