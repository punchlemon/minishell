#include "minishell.h"
#include "libft.h"

void	excute_cmd(t_cmd *cmd, char **splited_path_env, char **environ)
{
	char	*path_cmd;

	prepare_pipe_in_child(cmd);
	path_cmd = get_path_cmd(cmd->words[0], splited_path_env);
	execve(path_cmd, cmd->words, environ);
}

void	exe_cmds(t_cmd *cmds, char **environ, int *status)
{
	size_t	i;
	pid_t	pid;
	char	**splited_path_env;

	i = 0;
	splited_path_env = get_env();
	while (cmds[i].type != TAIL)
	{
		prepare_pipe(&cmds[i]);
		pid = fork();
		if (pid < 0)
			exit(1); // error fork
		if (pid == 0)
			excute_cmd(&cmds[i], splited_path_env, environ);
		else
			prepare_pipe_in_parent(&cmds[i]);
		waitpid(pid, status, 0);
		free_two_dimention_array(splited_path_env);
		if (WIFEXITED(*status))
			WEXITSTATUS(*status);
		i++;
	}
	free_two_dimention_array(splited_path_env);
}
