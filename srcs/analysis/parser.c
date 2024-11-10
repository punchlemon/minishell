/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:43:51 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/10 12:10:54by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "analysis.h"

void	delete_cmds(t_cmd *cmds)
{
	size_t	i;

	i = 0;
	while (cmds[i].tkns)
	{
		free(cmds[i].tkns);
		i++;
	}
	free(cmds);
}

void	delete_conds(t_cond *conds)
{
	size_t	i;

	i = 0;
	while (conds[i].type != TAIL)
	{
		delete_cmds(conds[i].cmds);
		i++;
	}
	free(conds);
}

static int	store_cmds(t_cmd *cmd, const t_tkn *src_tkns, size_t *s_i)
{
	size_t	c_len;
	size_t	c_i;

	if (src_tkns[*s_i].type == PIPE)
		(*s_i)++;
	c_len = 1;
	while (type_is_cmd(src_tkns[*s_i + c_len].type))
		c_len++;
	cmd->tkns = malloc(sizeof(t_tkn) * (c_len + 1));
	if (!cmd->tkns)
		return (0);
	cmd->tkns[c_len].type = TAIL;
	c_i = 0;
	while (c_i < c_len)
	{
		cmd->tkns[c_i].type = src_tkns[*s_i + c_i].type;
		cmd->tkns[c_i].head = src_tkns[*s_i + c_i].head;
		cmd->tkns[c_i].tail = src_tkns[*s_i + c_i].tail;
		c_i++;
	}
	return (1);
}

static int	store_cond(t_cond *cond, const t_tkn *src_tkns, size_t *s_i)
{
	size_t	p_len;
	size_t	p_i;
	size_t	tmp;

	tmp = 0;
	if (type_is_and_or(src_tkns[*s_i].type))
		cond->type = src_tkns[(*s_i)++].type;
	p_len = 1;
	while (type_is_cmds(src_tkns[*s_i + ++tmp].type))
		if (src_tkns[*s_i + tmp].type == PIPE)
			p_len++;
	cond->cmds = malloc(sizeof(t_tkn *) * (p_len + 1));
	if (!cond->cmds)
		return (cond->type = TAIL, 0);
	cond->cmds[p_len].tkns = NULL;
	p_i = 0;
	while (p_i < p_len)
	{
		if (!store_cmds(&((cond->cmds)[p_i]), src_tkns, s_i))
			return (delete_cmds(cond->cmds), cond->type = TAIL, 0);
		p_i++;
	}
	return (1);
}

t_cond	*parser(const t_tkn *src_tkns)
{
	t_cond	*conds;
	size_t	c_len;
	size_t	c_i;
	size_t	s_i;
	size_t	tmp;

	c_len = 1;
	tmp = 0;
	while (src_tkns[++tmp].type != TAIL)
		if (type_is_and_or(src_tkns[tmp].type))
			c_len++;
	s_i = 0;
	conds = malloc(sizeof(t_cond) * (c_len + 1));
	if (!conds)
		return (NULL);
	conds[0].type = HEAD;
	conds[c_len].type = TAIL;
	c_i = 0;
	while (c_i < c_len)
	{
		if (!store_cond(&conds[c_i], src_tkns, &s_i))
			return (delete_conds(conds), NULL);
		c_i++;
	}
	return (conds);
}
