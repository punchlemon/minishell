/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:09:54 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/25 16:56:17 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "sig.h"
#include "ft_printf.h"
#include "ft_printf_stderr.h"
#include "libft.h"
#include "builtin.h"

size_t	count_tkns_for_word(t_tkn *tkns);
size_t	count_word(t_tkn *tkns, t_env *env, char *st);
void	store_word(char *dst, t_tkn *tkns, t_env *env, char *st);

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

int	store_red(t_red *red, t_tkn *tkn, t_env *env, char *st)
{
	red->file_fd = -1;
	red->std_target_fd = -1;
	red->is_ambiguous = 0;
	if (red->type == DLESS)
	{
		if (!create_heredoc(red, tkn))
			return (0);
	}
	else if (!create_word(&(red->target), tkn, env, st))
		return (0);
	else if (is_env_variable(tkn->head, tkn->tail)
		&& !get_value(tkn->head, env, st))
	{
		red->target = ft_xcalloc(sizeof(char) * (tkn->tail - tkn->head + 1));
		if (!red->target)
			return (0);
		red->target[tkn->tail - tkn->head] = '\0';
		ft_memmove(red->target, tkn->head, tkn->tail - tkn->head);
		red->is_ambiguous = 1;
	}
	else if (!create_word(&(red->target), tkn, env, st))
		return (0);
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
			if (store_red(&(cmd->reds[r_i++]), &tkns[t_i], env, st))
				return (cmd->reds[--r_i].type = TAIL, delete_cmd_exe(cmd), 0);
		}
		else if (!is_env_variable(tkns[t_i].head, tkns[t_i].tail)
			|| get_value(tkns[t_i].head, env, st))
			if (!create_word(&(cmd->words[w_i++]), &tkns[t_i], env, st))
				return (delete_cmd_exe(cmd), 0);
		t_i += count_tkns_for_word(&tkns[t_i]);
	}
	cmd->words[w_i] = NULL;
	cmd->reds[r_i].type = TAIL;
	return (1);
}
