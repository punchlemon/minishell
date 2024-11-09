/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:43:51 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/09 14:36:55 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "analysis.h"

void	delete_cmds(t_tkn **cmds)
{
	size_t	i;

	i = 0;
	while (cmds[i])
		free(cmds[i]);
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

static void	store_cmd(t_tkn *cmd, const t_tkn *src, size_t *s_i)
{
	while (type_is_cmds(src[*s_i].type))
	{
	}
	if (src->type == PIPE)
		(*s_i)++;
	cmd->type = src[*s_i].type;
	cmd->head = src[*s_i].head;
	cmd->tail = src[*s_i].tail;
	(*s_i)++;
}

static int	store_cond(t_cond *cond, const t_tkn *src, size_t *s_i)
{
	size_t	c_len;
	size_t	c_i;

	if (type_is_and_or(src->type))
		cond->type = src[(*s_i)++].type;
	c_len = 1;
	while (type_is_cmds(src[++(*s_i)].type))
		if (src[*s_i].type == PIPE)
			c_len++;
	cond->cmds = malloc(sizeof(t_tkn *) * (c_len + 1));
	if (!cond->cmds)
		return (cond->type = TAIL, 0);
	s_i = 0;
	c_i = 0;
	while (c_i < c_len)
	{
		store_cmd(cond->cmds[c_i], src, s_i);
		c_i++;
	}
	return (cond->type = TAIL, 1);
}

t_cond	*parser(const t_tkn *src)
{
	t_cond	*conds;
	size_t	c_len;
	size_t	s_i;
	size_t	c_i;

	c_len = 1;
	s_i = 0;
	while (src[++s_i].type != TAIL)
		if (type_is_and_or(src[s_i].type))
			c_len++;
	conds = malloc(sizeof(t_cond) * (c_len + 1));
	if (!conds)
		return (NULL);
	conds->type = HEAD;
	conds[c_len].type = TAIL;
	s_i = 0;
	c_i = 0;
	while (c_i < c_len)
	{
		if (!store_cond(&conds[c_i], src, &s_i))
			return (delete_conds(conds), NULL);
		c_i++;
	}
	return (conds);
}
