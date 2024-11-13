#include "minishell.h"
#include "ft_printf.h"
#include "libft.h"

t_cmd	*expand_cmd(t_cmd *cmd, t_cmd_a *cmd_a)
{
	// size_t	cmd_len;
	// size_t	red_len;

	// cmd_len = count_cmd(cmd_a);
	// red_len = count_red(cmd_a);
	// cmd->words = malloc(sizeof(char *) * (cmd_len + 1));
	// if (!cmd->words)
	// 	return (NULL);
	// cmd->reds = malloc(sizeof(t_red) * (red_len + 1));
	// if (!cmd->reds)
	// 	return (free(cmd->words), NULL);
	(void)cmd_a;
	cmd->words = malloc(sizeof(char *) * 3);
	cmd->words[2] = NULL;
	cmd->words[1] = "hello";
	cmd->words[0] = "echo";
	cmd->reds = malloc(sizeof(t_red) * 1);
	cmd->reds[0].type = TAIL;
	// cmd->reds[0].type = LESS;
	// cmd->reds[0].target = "test_file";
	return (cmd);
}

void	excute_cmd(t_cmd *cmd, char **splited_path_env, char **environ)
{
	char	*path_cmd;

	prepare_pipe_in_child(cmd);
	// file open
	if (cmd->reds != NULL)
		set_redirects(cmd->reds);
	path_cmd = get_path_cmd(cmd->words[0], splited_path_env);
	execve(path_cmd, cmd->words, environ);
	// delete_cmd(cmd);
	write(2, "Error : execve\n", strlen("Error : execve\n"));
	exit(1);
}

int	exe_cmds(t_cmd_a *cmd_a_s, char **environ, int *status)
{
	size_t	i;
	pid_t	pid;
	int		tmp_in;
	int		tmp_out;
	char	**splited_path_env;
	t_cmd	*cmds; // 配列

	i = 0;
	splited_path_env = get_env();
	// while (cmd_a_s[i].tkns != NULL)
	// {
	// 	open_all_file_in_cmds(cmd_a_s[i].reds); // この関数は何をしている？
	// 	i++;
	// }
	i = 0;
	while (cmd_a_s[i].tkns)
		i++;
	cmds = malloc(sizeof(t_cmd) * (2));
	cmds[i].type = TAIL;
	while (i--)
	{
		cmds[i].type = HEAD;
		cmds[i].pipe_in[0] = 0;
		cmds[i].pipe_in[1] = -1;
		cmds[i].pipe_in[0] = -1;
		cmds[i].pipe_in[1] = 1;
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
		{
			// exit(1); // error fork
			operation_error("fork");
			break ;
		}
		if (pid == 0)
		{
			if (!expand_cmd(&cmds[i], &cmd_a_s[i])) // ここでmallocしてる
				return (0);
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
		delete_cmd(&cmds[i]);
	}
	free_two_dimention_array(splited_path_env);
	return (1);
}
