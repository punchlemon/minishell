/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:04:44 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/23 16:57:108:19 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_delete.h"

static size_t	count_cmd(const t_tkn *head, const t_tkn *tail)
{
	size_t	t_len;

	t_len = 0;
	if (head->type == PIPE)
		t_len++;
	if (head[t_len].type == LPAREN)
		t_len += match_paren(head) + 1;
	while (1)
	{
		if (head[t_len].type == PIPE || head + t_len == tail)
			break ;
		t_len++;
	}
	return (t_len);
}

static size_t	count_cmds(const t_tkn *head, const t_tkn *tail)
{
	size_t	t_i;
	size_t	c_len;

	c_len = 0;
	t_i = 0;
	while (1)
	{
		t_i += count_cmd(head + t_i, tail);
		c_len++;
		if (head + t_i == tail)
			return (c_len);
	}
}

static int	store_cmd(t_cmd *cmd, const char *src, const t_tkn *head, t_tkn *tail)
{
	if (head->type == LPAREN)
		cmd->type = SUBSHELL;
	else
		cmd->type = NORMAL;
	cmd->words = create_words(src, head, tail);
	cmd->conds = create_conds(src, head, tail);
	cmd->reds = create_redirects(src, head, tail);
	if (!cmd->conds || !cmd->words || !cmd->reds)
		return (0);
	return (1);
}

static t_cmd	*store_cmds(t_cmd *cmds, const char *src, const t_tkn *head,
	const t_tkn *tail)
{
	size_t	old_t_i;
	size_t	new_t_i;
	size_t	c_i;

	c_i = 0;
	old_t_i = 0;
	new_t_i = 0;
	while (1)
	{
		old_t_i = new_t_i;
		new_t_i += count_cmd(head + old_t_i, tail);
		if (!store_cmd(&cmds[c_i++], src, head + old_t_i, head + new_t_i))
			reuturn (NULL);
		if (head + new_t_i == tail)
			return (cmds);
	}
}

t_cmd	*create_cmds(const char *src, const t_tkn *head, const t_tkn *tail)
{
	t_cmd	*cmds;
	size_t	c_len;

	c_len = count_cmds(head, tail);
	cmds = malloc(sizeof(t_cmd) * (c_len + 1));
	if (!cmds)
		return (NULL);
	if (!store_cmds(cmds, src, head, tail))
		return (free(cmds), NULL);
	return (cmds);
}

void	delete_cmds(t_cmd *cmds)
{
	(void)cmds;
// 	size_t	i;

// 	i = 0;
// 	while (pipeline[i].type != TAIL)
// 	{
// 		delete_conds(pipeline[i].conds);
// 		delete_words(pipeline[i].words);
// 		delete_redirects(pipeline[i].redirects);
// 		i++;
// 	}
// 	free(pipeline);
}
