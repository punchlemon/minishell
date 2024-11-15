/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:17:03 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/15 17:23:36 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_printf.h"
#include "libft.h"

void	delete_cmd_exe(t_cmd *cmd)
{
	size_t	i;

	i = 0;
	while (cmd->words[i])
		free(cmd->words[i++]);
	i = 0;
	while (cmd->reds[i].type != TAIL)
		free(cmd->reds[i++].target);
	free(cmd->words);
	free(cmd->reds);
}

size_t	count_word(t_tkn *tkns)
{
	size_t	i;

	i = 1; // この関数を呼び出すときは確定でtype_is_wordsじゃないといけない
	while (tkns[i].type != TAIL && !type_is_red(tkns[i].type))
	{
		if (tkns[i].head - tkns[i - 1].tail)
			return (i);
		i++;
	}
	return (i);
}

void	count_cmd(size_t *words_len, size_t *reds_len, t_tkn *tkns)
{
	size_t	t_i;

	*words_len = 0;
	*reds_len = 0;
	t_i = 0;
	while (tkns[t_i].type != TAIL)
	{
		if (type_is_red(tkns[t_i].type))
		{
			(*reds_len)++;
			t_i++;
		}
		else
			(*words_len)++;
		t_i += count_word(&tkns[t_i]);
	}
}

int	store_word(char **pp, t_tkn *tkns, size_t tmp)
{
	size_t		p_i;
	size_t		t_i;
	size_t		word_len;
	const char	*start;

	word_len = 0;
	t_i = 0;
	while (t_i < tmp)
	{
		word_len += tkns[t_i].tail - tkns[t_i].head;
		if (tkns[t_i].type == SINGLE || tkns[t_i].type == DOUBLE)
			word_len -= 2;
		t_i++;
	}
	*pp = malloc(sizeof(char) * (word_len + 1));
	if (!(*pp))
		return (0);
	(*pp)[word_len] = '\0';
	t_i = 0;
	p_i = 0;
	while (t_i < tmp)
	{
		start = tkns[t_i].head;
		word_len = tkns[t_i].tail - tkns[t_i].head;
		if (tkns[t_i].type == SINGLE || tkns[t_i].type == DOUBLE)
		{
			start += 1;
			word_len -= 2;
		}
		ft_memmove(&(*pp)[p_i], start, word_len);
		p_i += word_len;
		t_i++;
	}
	return (1);
}

int	store_cmd(t_cmd *cmd, t_tkn *tkns)
{
	size_t	t_i;
	size_t	w_i;
	size_t	r_i;
	size_t	tmp;

	t_i = 0;
	w_i = 0;
	r_i = 0;
	while (tkns[t_i].type != TAIL)
	{
		if (type_is_red(tkns[t_i].type))
		{
			cmd->reds[r_i].type = tkns[t_i].type;
			t_i++;
			tmp = count_word(&tkns[t_i]);
			if (!store_word(&(cmd->reds[r_i].target), &tkns[t_i], tmp))
				return (cmd->reds[r_i].type = TAIL, delete_cmd_exe(cmd), 0);
			r_i++;
		}
		else
		{
			tmp = count_word(&tkns[t_i]);
			if (!store_word(&(cmd->words[w_i]), &tkns[t_i], tmp))
				return (delete_cmd_exe(cmd), 0);
			w_i++;
		}
		t_i += tmp;
	}
	return (1);
}

t_cmd	*expand_cmd(t_cmd *cmd, t_tkn *tkns)
{
	size_t	words_len;
	size_t	reds_len;

	count_cmd(&words_len, &reds_len, tkns);
	cmd->words = malloc(sizeof(char *) * (words_len + 1));
	if (!cmd->words)
		return (NULL);
	cmd->words[words_len] = NULL;
	cmd->reds = malloc(sizeof(t_red) * (reds_len + 1));
	if (!cmd->reds)
		return (free(cmd->words), NULL);
	cmd->reds[reds_len].type = TAIL;
	if (!store_cmd(cmd, tkns))
		return (NULL);
	return (cmd);
}

void	excute_cmd(t_cmd *cmd, char **splited_path_env, char **environ)
{
	char	*path_cmd;

	prepare_pipe_in_child(cmd);
	// file open
	open_file(cmd->reds);
	if (cmd->reds != NULL)
		set_redirects(cmd->reds);
	path_cmd = get_path_cmd(cmd->words[0], splited_path_env);
	execve(path_cmd, cmd->words, environ);
	write(2, "Error : execve\n", strlen("Error : execve\n"));
	delete_cmd_exe(cmd);
	exit(1);
}

int	excute_builtin_cmd(t_env **env, char *cmd, char **args)
{
	if (strcmp(cmd, "cd") == 0)
		return (builtin_cd(env, args));
	else if (strcmp(cmd, "pwd") == 0)
		return (builtin_pwd());
	else if (strcmp(cmd, "echo") == 0)
		return (builtin_echo(args));
	if (strcmp(cmd, "env") == 0)
		return (builtin_env(env, args));
	else if (strcmp(cmd, "exit") == 0)
		return (builtin_exit(*env, args));
	else if (strcmp(cmd, "export") == 0)
		return (builtin_export(env, args));
	else if (strcmp(cmd, "unset") == 0)
		return (builtin_unset(env, args));
	else
		return (1);
}

int	is_builtin(char *cmd)
{
	if (strcmp(cmd, "cd") == 0 || strcmp(cmd, "echo") == 0 || \
		strcmp(cmd, "env") == 0 || strcmp(cmd, "exit") == 0 || \
		strcmp(cmd, "export") == 0 || strcmp(cmd, "pwd") == 0 || \
		strcmp(cmd, "unset") == 0)
		return (1);
	return (0);
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
		cmds[i].pipe_out[0] = -1;
		cmds[i].pipe_out[1] = 1;
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
		else if (pid == 0 && is_builtin(cmds[i].words[0]))
			exit(execute_builtin_cmd(cmds[i].words[0], &(cmds[i].words[1])));
		else if (pid == 0)
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
	free(cmds);
	free_two_dimention_array(splited_path_env);
	return (1);
}
