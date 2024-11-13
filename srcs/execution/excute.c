#include "minishell.h"
#include "ft_printf.h"
#include "libft.h"

void	delete_cmds(t_cmd *cmds)
{
	size_t	i;

	i = 0;
	while (cmds[i].type != TAIL)
	{
		free(cmds[i].words);
		free(cmds[i].reds);
		i++;
	}
	free(cmds);
}

void	count_word(t_tkn *tkns, size_t *i)
{
	(*i)++; // この関数を呼び出すときは確定でtype_is_wordsじゃないといけない
	while (tkns[*i].type != TAIL && !type_is_red(tkns[*i].type))
	{
		if ((tkns[*i].head - tkns[*i - 1].tail) != 1)
			return ;
		*i++;
	}
}

void	count_cmd(size_t *cmd_len, size_t *red_len, t_tkn *tkns)
{
	size_t	i;

	*cmd_len = 0;
	*red_len = 0;
	i = 0;
	while (tkns[i].type != TAIL)
	{
		if (type_is_red(tkns[i].type))
		{
			(*red_len)++;
			i++;
		}
		else
			(*cmd_len)++;
		count_word(tkns, &i);
	}
	return (i);
}

void	store_cmd(t_cmd *cmd, t_tkn *tkns)
{
}

t_cmd	*expand_cmd(t_cmd *cmd, t_tkn *tkns)
{
	size_t	cmd_len;
	size_t	red_len;

	count_cmd(&cmd_len, &red_len, tkns);
	cmd->words = malloc(sizeof(char *) * (cmd_len + 1));
	if (!cmd->words)
		return (NULL);
	cmd->reds = malloc(sizeof(t_red) * (red_len + 1));
	if (!cmd->reds)
		return (free(cmd->words), NULL);
	store_cmd(cmd, tkns);
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
	cmds = malloc(sizeof(t_cmd) * (i + 1));
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
			if (!expand_cmd(&cmds[i], cmd_a_s[i].tkns))
				return (0);
			excute_cmd(&cmds[i], splited_path_env, environ);
		}
		else
			prepare_pipe_in_parent(&cmds[i]);
		waitpid(pid, status, 0);
		dup2(tmp_in, 0); // test
		dup2(tmp_out, 1); // test
		close(tmp_in); // test
		close(tmp_out); // test
		if (WIFEXITED(*status))
			WEXITSTATUS(*status);
		i++;
	}
	delete_cmds(cmds);
	free_two_dimention_array(splited_path_env);
	return (1);
}
