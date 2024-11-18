/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:17:03 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/18 15:24:42 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "sig.h"
#include "ft_printf.h"
#include "libft.h"
#include "builtin.h"

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

size_t	count_tkns_for_word(t_tkn *tkns)
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
		t_i += count_tkns_for_word(&tkns[t_i]);
	}
}

int	ft_is_charactor(char c)
{
	return (c == '_' || ft_isalpha(c) || ft_isdigit(c));
}

size_t	charactors_len(const char *src)
{
	size_t	len;

	len = 1;
	while (ft_is_charactor(src[len]))
		len++;
	return (len);
}

size_t	check_valiable(const char *src)
{
	if (*src != '$')
		return (0);
	if (src[1] != '_' && !ft_isalpha(src[1]) && src[1] != '?')
		return (0);
	if (src[1] == '?')
		return (2);
	return (charactors_len(src));
}

char	*get_value(const char *src, t_env *env, char *st)
{
	char	*key;
	size_t	len;
	char	*value;

	if (*src != '$')
		return (NULL);
	if (src[1] != '_' && !ft_isalpha(src[1]) && src[1] != '?')
		return (NULL);
	if (src[1] == '?')
		return (st);
	len = charactors_len(src);
	key = malloc(sizeof(char) * (len + 1));
	if (!key)
		exit(1);
	key[len] = '\0';
	value = search_env_return_its_value(env, key);
	free(key);
	return (value);
}

void	count_word_in_a_tkn(t_tkn *tkns, size_t *word_len, t_env *env, char *st)
{
	size_t	i;
	size_t	sub;
	char	*tmp;

	*word_len += tkns->tail - tkns->head;
	if (tkns->type == NORMAL || tkns->type == DOUBLE)
	{
		i = 0;
		while (tkns->head[i])
		{
			if (check_valiable(&tkns->head[i]))
			{
				tmp = get_value(&tkns->head[i], env, st);
				if (tmp)
					*word_len += ft_strlen(tmp);
				sub = charactors_len(&tkns->head[i]);
				*word_len -= sub;
				i += sub;
			}
			else
				i++;
		}
	}
	if (tkns->type == SINGLE || tkns->type == DOUBLE)
		*word_len -= 2;
}

size_t	count_word(t_tkn *tkns, t_env *env, char *st)
{
	size_t	t_i;
	size_t	word_len;
	size_t	tmp;

	word_len = 0;
	t_i = 0;
	tmp = count_tkns_for_word(tkns);
	while (t_i < tmp)
	{
		count_word_in_a_tkn(&tkns[t_i], &word_len, env, st);
		t_i++;
	}
	return (word_len);
}

void	store_word_in_a_tkn(char *dst, t_tkn *tkns, t_env *env, char *st)
{
	size_t	i;
	size_t	d_i;
	char	*tmp;

	i = 0;
	d_i = 0;
	if (tkns->type == NORMAL || tkns->type == DOUBLE)
	{
		while (&tkns->head[i] < tkns->tail)
		{
			if (check_valiable(&tkns->head[i]))
			{
				tmp = get_value(&tkns->head[i], env, st);
				if (tmp)
					ft_memmove(&dst[d_i], tmp, ft_strlen(tmp));
				i += charactors_len(&tkns->head[i]);
				d_i += ft_strlen(tmp);
			}
			else
				dst[d_i++] = tkns->head[i++];
		}
	}
	else
		ft_memmove(dst, &(tkns->head[1]), tkns->tail - tkns->head - 1);
}

void	store_word(char *dst, t_tkn *tkns, t_env *env, char *st)
{
	size_t	d_i;
	size_t	t_i;
	size_t	tmp;

	t_i = 0;
	d_i = 0;
	tmp = count_tkns_for_word(tkns);
	while (t_i < tmp)
	{
		store_word_in_a_tkn(&dst[d_i], &tkns[t_i], env, st);
		count_word_in_a_tkn(&tkns[t_i], &d_i, env, st);
		t_i++;
	}
}

int	create_word(char **pp, t_tkn *tkns, t_env *env, char *st)
{
	size_t	word_len;

	word_len = count_word(tkns, env, st);
	*pp = malloc(sizeof(char) * (word_len + 1));
	if (!(*pp))
		return (0);
	(*pp)[word_len] = '\0';
	store_word(*pp, tkns, env, st);
	return (1);
}

int	store_cmd(t_cmd *cmd, t_tkn *tkns, t_env *env, char *st)
{
	size_t	t_i;
	size_t	w_i;
	size_t	r_i;

	t_i = 0;
	w_i = 0;
	r_i = 0;
	while (tkns[t_i].type != TAIL)
	{
		if (type_is_red(tkns[t_i].type))
		{
			cmd->reds[r_i].type = tkns[t_i++].type;
			if (!create_word(&(cmd->reds[r_i].target), &tkns[t_i], env, st))
				return (cmd->reds[r_i].type = TAIL, delete_cmd_exe(cmd), 0);
			r_i++;
		}
		else
		{
			if (!create_word(&(cmd->words[w_i]), &tkns[t_i], env, st))
				return (delete_cmd_exe(cmd), 0);
			w_i++;
		}
		t_i += count_tkns_for_word(&tkns[t_i]);
	}
	return (1);
}

t_cmd	*expand_cmd(t_cmd *cmd, t_tkn *tkns, t_env *env, int status)
{
	size_t	words_len;
	size_t	reds_len;
	char	*st;

	st = ft_itoa(status);
	if (!st)
		return (NULL);
	count_cmd(&words_len, &reds_len, tkns);
	cmd->words = malloc(sizeof(char *) * (words_len + 1));
	if (!cmd->words)
		return (free(st), NULL);
	cmd->words[words_len] = NULL;
	cmd->reds = malloc(sizeof(t_red) * (reds_len + 1));
	if (!cmd->reds)
		return (free(st), free(cmd->words), NULL);
	cmd->reds[reds_len].type = TAIL;
	if (!store_cmd(cmd, tkns, env, st))
		return (free(st), NULL);
	return (free(st), cmd);
}

size_t	count_env_len(t_env *env)
{
	size_t	len;

	len = 0;
	while (env != NULL)
	{
		env = env->next;
		len++;
	}
	return (len);
}

char	**env_to_environ(t_env *env)
{
	char	**strs;
	char	*tmp;
	size_t	i;

	strs = (char **)malloc(sizeof(char *) * (count_env_len(env) + 1));
	if (strs == NULL)
		return (NULL);
	i = 0;
	while (env != NULL && env->value != NULL)
	{
		strs[i] = ft_strjoin(env->key, "=");
		if (strs[i] == NULL)
			return (free_two_dimention_array(strs), NULL);
		tmp = strs[i];
		strs[i] = ft_strjoin(strs[i], env->value);
		if (strs[i] == NULL)
			return (free_two_dimention_array(strs), NULL);
		free(tmp);
		env = env->next;
		i++;
	}
	strs[i] = NULL;
	return (strs);
}

void	excute_cmd(t_cmd *cmd, char **splited_path_env, t_env **env)
{
	char	*path_cmd;
	char	**environ;

	set_exec_child_handler();
	prepare_pipe_in_child(cmd);
	open_file(cmd->reds);
	if (cmd->reds != NULL)
		set_redirects(cmd->reds);
	if (cmd->words[0] == NULL) // redirectのみのときは終了
		exit(0);
	path_cmd = get_path_cmd(cmd->words[0], splited_path_env);
	environ = env_to_environ(*env);
	if (environ == NULL)
		exit(1);
	execve(path_cmd, cmd->words, environ);
	write(2, "Error : execve\n", strlen("Error : execve\n"));
	exit(1);
}

int	execute_builtin_cmd(t_env **env, t_cmd *cmd, int is_child)
{
	char	*command_name;
	char	**args;
	if (is_child)
	{
		prepare_pipe_in_child(cmd);
	}
	set_redirects(cmd->reds);
	command_name = cmd->words[0];
	args = &cmd->words[1];
	if (strcmp(command_name, "cd") == 0)
		return (builtin_cd(env, args));
	else if (strcmp(command_name, "pwd") == 0)
		return (builtin_pwd());
	else if (strcmp(command_name, "echo") == 0)
		return (builtin_echo(args));
	if (strcmp(command_name, "env") == 0)
		return (builtin_env(env, args));
	else if (strcmp(command_name, "exit") == 0)
		return (builtin_exit(*env, args));
	else if (strcmp(command_name, "export") == 0)
		return (builtin_export(env, args));
	else if (strcmp(command_name, "unset") == 0)
		return (builtin_unset(env, args));
	else // fatal_error
		return (1);
}

int	is_builtin(char *cmd)
{
	if (cmd == NULL)
		return (0);
	if (strcmp(cmd, "cd") == 0 || strcmp(cmd, "echo") == 0 || \
		strcmp(cmd, "env") == 0 || strcmp(cmd, "exit") == 0 || \
		strcmp(cmd, "export") == 0 || strcmp(cmd, "pwd") == 0 || \
		strcmp(cmd, "unset") == 0)
	{
		return (1);
	}
	return (0);
}

int	destruct_forks(t_cmd *cmds, size_t len)
{
	pid_t	pid;
	size_t	i;
	int		status;
	int		return_status;

	i = 0;
	while (i < len)
	{
		pid = cmds[i].pid;
		waitpid(pid, &status, 0);
		// if (WIFSIGNALED(status))
		if (WIFEXITED(status))
			return_status = WEXITSTATUS(status);
		i++;
	}
	free(cmds);
	return (return_status);
}

t_cmd	*init_cmds(t_cmd_a *cmd_a_s)
{
	t_cmd	*cmds;
	size_t	len;

	len = 0;
	while (cmd_a_s[len].tkns)
		len++;
	cmds = malloc(sizeof(t_cmd) * (len + 1));
	if (cmds == NULL)
		return (NULL);
	cmds[len].type = TAIL;
	while (len--)
	{
		cmds[len].type = NORMAL;
		cmds[len].pipe_in[0] = 0;
		cmds[len].pipe_in[1] = -1;
		cmds[len].pipe_out[0] = -1;
		cmds[len].pipe_out[1] = 1;
	}
	return (cmds);
}

int	exe_cmds(t_cmd_a *cmd_a_s, t_env *env, int *status)
{
	size_t	i;
	pid_t	pid;
	int		tmp_in; // test
	int		tmp_out; // test
	char	**splited_path_env;
	t_cmd	*cmds;

	splited_path_env = get_env(env);
	cmds = init_cmds(cmd_a_s);
	if (cmds == NULL)
		return (1); // free
	i = 0;
	while (cmds[i].type != TAIL)
	{
		tmp_in = dup(0); // test
		tmp_out = dup(1); // test
		if (prepare_pipe(&cmds[i]))
			break ;
		if (!expand_cmd(&cmds[i], cmd_a_s[i].tkns, env, *status))
			return (0);
		if (is_builtin(cmds[i].words[0]) && i == 0 && cmds[i + 1].type == TAIL)
			execute_builtin_cmd(&env, &cmds[i], 0);
		else
		{
			pid = fork();
			if (pid < 0)
			{
				operation_error("fork");
				break ;
			}
			else if (pid == 0 && is_builtin(cmds[i].words[0]))
				exit(execute_builtin_cmd(&env, &cmds[i], 1));
			else if (pid == 0)
				excute_cmd(&cmds[i], splited_path_env, &env);
			else
				prepare_pipe_in_parent(&cmds[i]);
			cmds->pid = pid;
			set_exec_handler(true);
		}
		dup2(tmp_in, 0); // test
		dup2(tmp_out, 1); // test
		close(tmp_in); // test
		close(tmp_out); // test
		delete_cmd_exe(&cmds[i]);
		i++;
	}
	free_two_dimention_array(splited_path_env);
	return (destruct_forks(cmds, i));
}
