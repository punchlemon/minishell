/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:17:03 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/21 12:46:45 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "sig.h"
#include "ft_printf.h"
#include "ft_printf_stderr.h"
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

	len = 2;
	while (ft_is_charactor(src[len]))
		len++;
	return (len);
}

size_t	check_valiable(const char *src)
{
	if (src[0] != '$')
		return (0);
	if (src[1] == '?')
		return (2);
	if (src[1] == '_' || ft_isalpha(src[1]))
		return (charactors_len(src));
	return (0);
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
	len = check_valiable(src) - 1;
	key = malloc(sizeof(char) * (len + 1));
	if (!key)
		exit(1);
	key[len] = '\0';
	ft_memmove(key, &src[1], len);
	value = search_env_return_its_value(env, key);
	free(key);
	return (value);
}

void	count_word_in_a_tkn(t_tkn *tkn, size_t *word_len, t_env *env, char *st)
{
	size_t	i;
	size_t	sub;
	char	*tmp;

	*word_len += tkn->tail - tkn->head;
	if (tkn->type == DOUBLE)
	{
		i = 1;
		while (&tkn->head[i + 1] < tkn->tail)
		{
			sub = check_valiable(&tkn->head[i]);
			if (sub)
			{
				tmp = get_value(&tkn->head[i], env, st);
				if (tmp)
					*word_len += ft_strlen(tmp);
				*word_len -= sub;
				i += sub;
			}
			else
				i++;
		}
	}
	else if (tkn->type == NORMAL || tkn->type == DOUBLE)
	{
		i = 0;
		while (&tkn->head[i] < tkn->tail)
		{
			sub = check_valiable(&tkn->head[i]);
			if (sub)
			{
				tmp = get_value(&tkn->head[i], env, st);
				if (tmp)
					*word_len += ft_strlen(tmp);
				*word_len -= sub;
				i += sub;
			}
			else
				i++;
		}
	}
	if (tkn->type == SINGLE || tkn->type == DOUBLE)
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

void	store_word_in_a_tkn(char *dst, t_tkn *tkn, t_env *env, char *st)
{
	size_t	i;
	size_t	sub;
	size_t	d_i;
	char	*tmp;

	d_i = 0;
	if (tkn->type == DOUBLE)
	{
		i = 1;
		while (&tkn->head[i + 1] < tkn->tail)
		{
			sub = check_valiable(&tkn->head[i]);
			if (sub)
			{
				tmp = get_value(&tkn->head[i], env, st);
				i += sub;
				if (!tmp)
					continue ;
				ft_memmove(&dst[d_i], tmp, ft_strlen(tmp));
				d_i += ft_strlen(tmp);
			}
			else
				dst[d_i++] = tkn->head[i++];
		}
	}
	else if (tkn->type == NORMAL)
	{
		i = 0;
		while (&tkn->head[i] < tkn->tail)
		{
			sub = check_valiable(&tkn->head[i]);
			if (sub)
			{
				tmp = get_value(&tkn->head[i], env, st);
				i += sub;
				if (!tmp)
					continue ;
				ft_memmove(&dst[d_i], tmp, ft_strlen(tmp));
				d_i += ft_strlen(tmp);
			}
			else
				dst[d_i++] = tkn->head[i++];
		}
	}
	else
		ft_memmove(dst, &(tkn->head[1]), tkn->tail - tkn->head - 2);
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
			cmd->reds[r_i].file_fd = -1;
			cmd->reds[r_i].std_target_fd = -1;
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

void	check_is_file(char *path_cmd, char *cmd)
{
	struct stat		st;

	// ft_printf_stderr("path_cmd = %s\n", path_cmd); // test
	// ft_printf_stderr("cmd = %s\n", cmd); // test
	if (strcmp(cmd, "") == 0)
		exit(0);
	if (stat(path_cmd, &st) < 0)
	{
		perror("stat");
		exit(1);
	}
	if (st.st_mode & S_IFDIR && !(st.st_mode & S_IFREG))
	{
		ft_printf_stderr("bash: %s: Is a directory\n", cmd);
		exit(126);
	}
}

void	excute_cmd(t_cmd *cmd, char **splited_path_env, t_env **env)
{
	char	*path_cmd;
	char	**environ;

	set_exec_child_handler();
	prepare_pipe_in_child(cmd);
	open_file(cmd->reds, 1);
	if (cmd->reds != NULL)
		set_redirects(cmd->reds);
	if (cmd->words[0] == NULL) // redirectのみのときは終了
		exit(0);
	path_cmd = get_path_cmd(cmd->words[0], splited_path_env);
	// check_is_file
	check_is_file(path_cmd, cmd->words[0]);
	environ = env_to_environ(*env);
	if (environ == NULL)
		exit(1);
	execve(path_cmd, cmd->words, environ);
	write(2, "Error : execve\n", strlen("Error : execve\n"));
	exit(1);
}

int	execute_builtin_cmd(t_env **env, t_cmd *cmd, int status, int is_child)
{
	char	*command_name;
	char	**args;

	if (is_child)
	{
		prepare_pipe_in_child(cmd);
	}
	if (!open_file(cmd->reds, is_child))
		return (1); // 1 ではない気がする
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
	if (strcmp(command_name, "env") == 0)
		return (builtin_env(env, args));
	else if (strcmp(command_name, "exit") == 0)
		return (builtin_exit(*env, args, status));
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
	size_t	i;
	int		status;
	int		return_status;

	i = 0;
	status = 0;
	while (i < len)
	{
		waitpid(cmds[i].pid, &status, 0);
		// if (WIFSIGNALED(status))
		if (WIFEXITED(status))
			return_status = WEXITSTATUS(status);
		i++;
	}
	// free(cmds);
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
		cmds[len].pid = 0;
	}
	return (cmds);
}

int	exe_cmds(t_cmd_a *cmd_a_s, t_env **env, int *status)
{
	size_t	i;
	int		tmp_in; // test
	int		tmp_out; // test
	char	**splited_path_env;
	t_cmd	*cmds;

	splited_path_env = get_env(*env);
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
		if (!expand_cmd(&cmds[i], cmd_a_s[i].tkns, *env, *status))
			return (0);
		if (is_builtin(cmds[i].words[0]) && i == 0 && cmds[i + 1].type == TAIL)
		{
			*status = execute_builtin_cmd(env, &cmds[i], *status, 0);
			free_two_dimention_array(splited_path_env);
			delete_cmd_exe(cmds);
			free(cmds);
			dup2(tmp_in, 0);
			dup2(tmp_out, 1);
			close(tmp_in);
			close(tmp_out);
			return (*status); // unnecessary ?
		}
		cmds[i].pid = fork();
		if (cmds[i].pid < 0)
		{
			operation_error("fork");
			break ;
		}
		else if (cmds[i].pid == 0 && is_builtin(cmds[i].words[0]))
			exit(execute_builtin_cmd(env, &cmds[i], *status, 1));
		else if (cmds[i].pid == 0)
			excute_cmd(&cmds[i], splited_path_env, env);
		else
			prepare_pipe_in_parent(&cmds[i]);
		set_exec_handler(true);

		dup2(tmp_in, 0);
		dup2(tmp_out, 1);
		close(tmp_in);
		close(tmp_out);
		delete_cmd_exe(&cmds[i]);
		i++;
	}
	*status = destruct_forks(cmds, i);
	free_two_dimention_array(splited_path_env);
	free(cmds);
	return (*status); // unnecessary ?
}
