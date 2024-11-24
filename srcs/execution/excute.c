/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:17:03 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/24 19:12:00 by hnakayam         ###   ########.fr       */
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
	key = ft_xcalloc(sizeof(char) * (len + 1));
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
	*pp = ft_xcalloc(sizeof(char) * (word_len + 1));
	if (!(*pp))
		return (0);
	(*pp)[word_len] = '\0';
	store_word(*pp, tkns, env, st);
	return (1);
}

int	is_env_variable(const char *head, const char *tail)
{
	size_t	len;
	size_t	i;

	len = tail - head;
	if (*head != '$' || len < 2)
		return (0);
	if (head[1] != '_' && !ft_isalpha(head[1]))
		return (0);
	i = 1;
	while (i < len)
	{
		if (!ft_is_charactor(head[i]))
			return (0);
		i++;
	}
	return (1);
}

size_t	count_heredoc(t_tkn *tkns, size_t t_len)
{
	size_t	t_i;
	size_t	tmp;
	size_t	len;

	len = 0;
	t_i = 0;
	while (t_i < t_len)
	{
		tmp = tkns[t_i].tail - tkns[t_i].head;
		if (tkns[t_i].type == DOUBLE || tkns[t_i].type == SINGLE)
			tmp -= 2;
		len += tmp;
		t_i++;
	}
	return (len);
}

size_t	store_heredoc(t_red *red, t_tkn *tkns, size_t t_len)
{
	size_t	t_i;
	size_t	tmp;
	size_t	len;

	len = 0;
	t_i = 0;
	while (t_i < t_len)
	{
		tmp = tkns[t_i].tail - tkns[t_i].head;
		if (tkns[t_i].type == DOUBLE || tkns[t_i].type == SINGLE)
		{
			tmp -= 2;
			red->type = NO_EX_DLESS;
			ft_memmove(&((red->target)[len]), &(tkns[t_i].head[1]), tmp);
		}
		else
			ft_memmove(&((red->target)[len]), tkns[t_i].head, tmp);
		len += tmp;
		t_i++;
	}
	return (len);
}

int	create_heredoc(t_red *red, t_tkn *tkns)
{
	size_t	len;
	size_t	t_len;

	len = 0;
	t_len = count_tkns_for_word(tkns);
	len = count_heredoc(tkns, t_len);
	red->target = ft_xcalloc(sizeof(char) * (len + 1));
	if (!(red->target))
		return (0);
	store_heredoc(red, tkns, t_len);
	(red->target)[len] = '\0';
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
			cmd->reds[r_i].file_fd = -1;
			cmd->reds[r_i].std_target_fd = -1;
			cmd->reds[r_i].type = tkns[t_i++].type;
			cmd->reds[r_i].is_ambiguous = 0;
			if (cmd->reds[r_i].type == DLESS)
			{
				if (!create_heredoc(&(cmd->reds[r_i]), &tkns[t_i]))
					return (cmd->reds[r_i].type = TAIL, delete_cmd_exe(cmd), 0);
			}
			else if (!create_word(&(cmd->reds[r_i].target), &tkns[t_i], env, st))
				return (cmd->reds[r_i].type = TAIL, delete_cmd_exe(cmd), 0);
			else if (is_env_variable(tkns[t_i].head, tkns[t_i].tail) && !get_value(tkns[t_i].head, env, st))
			{
				cmd->reds[r_i].target = ft_xcalloc(sizeof(char) * (tkns[t_i].tail - tkns[t_i].head + 1));
				if (!cmd->reds[r_i].target)
					return (cmd->reds[r_i].type = TAIL, delete_cmd_exe(cmd), 0);
				cmd->reds[r_i].target[tkns[t_i].tail - tkns[t_i].head] = '\0';
				ft_memmove(cmd->reds[r_i].target, tkns[t_i].head, tkns[t_i].tail - tkns[t_i].head);
				cmd->reds[r_i].is_ambiguous = 1;
			}
			else if (!create_word(&(cmd->reds[r_i].target), &tkns[t_i], env, st))
					return (cmd->reds[r_i].type = TAIL, delete_cmd_exe(cmd), 0);
			r_i++;
		}
		else
		{
			if (!is_env_variable(tkns[t_i].head, tkns[t_i].tail) || get_value(tkns[t_i].head, env, st))
			{
				if (!create_word(&(cmd->words[w_i]), &tkns[t_i], env, st))
					return (delete_cmd_exe(cmd), 0);
				w_i++;
			}
		}
		t_i += count_tkns_for_word(&tkns[t_i]);
	}
	cmd->words[w_i] = NULL;
	cmd->reds[r_i].type = TAIL;
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
	cmd->words = ft_xcalloc(sizeof(char *) * (words_len + 1));
	if (!cmd->words)
		return (free(st), NULL);
	cmd->reds = ft_xcalloc(sizeof(t_red) * (reds_len + 1));
	if (!cmd->reds)
		return (free(st), free(cmd->words), NULL);
	if (!store_cmd(cmd, tkns, env, st))
		return (free(st), NULL);
	return (free(st), cmd);
}
