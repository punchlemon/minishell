#include "minishell.h"
#include "ft_printf.h"
#include "libft.h"

int	do_heredoc(char *delimiter) // have to create
{
	(void)delimiter;
	return (-1);
}

void	do_redirect(t_red *red)
{
	if (dup2(red->file_fd, red->std_target_fd) < 0)
		exit(1); // error dup2
	close(red->file_fd);
}

void	set_redirects(t_red *reds)
{
	size_t	i;

	i = 0;
	while (reds[i].type != TAIL)
	{
		do_redirect(&reds[i]);
		i++;
	}
}

void	excute_cmd(t_cmd *cmd, char **splited_path_env, char **environ)
{
	char	*path_cmd;

	prepare_pipe_in_child(cmd);
	if (cmd->reds != NULL)
	{
		set_redirects(cmd->reds);
	}
	path_cmd = get_path_cmd(cmd->words[0], splited_path_env);
	execve(path_cmd, cmd->words, environ);
}

void	open_all_file_in_cmds(t_red *reds)
{
	size_t	i;

	i = 0;
	while (reds[i].type != TAIL)
	{
		if (reds[i].type == LESS)
		{
			reds[i].file_fd = open(reds[i].target, O_RDONLY);
			reds[i].std_target_fd = 0;
		}
		else if (reds[i].type == GREAT)
		{
			reds[i].file_fd = open(reds[i].target, \
					O_CREAT | O_WRONLY | O_TRUNC, 0644);
			reds[i].std_target_fd = 1;
		}
		else if (reds[i].type == DLESS)
		{
			reds[i].file_fd = do_heredoc(reds[i].target);
			reds[i].std_target_fd = 0;
		}
		else if (reds[i].type == DGREAT)
		{
			reds[i].file_fd = open(reds[i].target, \
					O_CREAT | O_WRONLY | O_APPEND, 0644);
			reds[i].std_target_fd = 1;
		}
		i++;
	}
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
		prepare_pipe(&cmds[i]);
		pid = fork();
		if (pid < 0)
			exit(1); // error fork
		if (pid == 0)
		{
			excute_cmd(&cmds[i], splited_path_env, environ);
		}
		else
			prepare_pipe_in_parent(&cmds[i]);
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
