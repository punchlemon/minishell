/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_count_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:31:30 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/29 16:35:49 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_create.h"

size_t	count_cmds(const t_tkn *tkns, const size_t t_len)
{
	size_t	t_i;
	size_t	c_len;

	c_len = 0;
	t_i = 0;
	while (t_i < t_len)
	{
		if (t_i)
			t_i++;
		t_i += count_tkns_for_cmd(&tkns[t_i], t_len);
		c_len++;
	}
	return (c_len);
}

static int	store_subshell(t_cmd *cmd, const char *src, const t_tkn *tkns,
	const size_t t_len)
{
	size_t	tmp_len;

	cmd->type = SUBSHELL;
	tmp_len = match_paren(tkns);
	cmd->conds = create_conds(src, &tkns[1], tmp_len - 1);
	if (!cmd->conds)
		return (0);
	cmd->words = NULL;
	cmd->reds = create_reds(src, &tkns[tmp_len + 1], t_len - (tmp_len + 1));
	if (!cmd->reds)
		return (delete_conds(cmd->conds), 0);
	return (1);
}

static int	store_normal(t_cmd *cmd, const char *src, const t_tkn *tkns,
	const size_t t_len)
{
	cmd->type = NORMAL;
	cmd->words = create_words(src, tkns, t_len);
	if (!cmd->words)
		return (0);
	cmd->conds = NULL;
	cmd->reds = create_reds(src, tkns, t_len);
	if (!cmd->reds)
		return (delete_words(cmd->words), 0);
	return (1);
}

int	store_cmds(t_cmd *cmds, const char *src, const t_tkn *tkns,
	const size_t t_len)
{
	size_t	t_i;
	size_t	tmp_len;
	size_t	c_i;

	c_i = 0;
	t_i = 0;
	while (t_i < t_len)
	{
		if (t_i)
			t_i++;
		tmp_len = count_cmd(&tkns[t_i], t_len);
		if (tkns->type == LPAREN)
		{
			if (!store_subshell(&cmds[c_i], src, &tkns[t_i], tmp_len))
				return (cmds[c_i].type = TAIL, delete_cmds(cmds), 0);
		}
		else if (!store_normal(&cmds[c_i], src, &tkns[t_i], tmp_len))
			return (cmds[c_i].type = TAIL, delete_cmds(cmds), 0);
		t_i += tmp_len;
		c_i++;
	}
	return (cmds[c_i].type = TAIL, 1);
}
