/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:04:44 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/23 01:02:57 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_delete.h"

static size_t	count_cmds(const t_tkn *head, const t_tkn *tail)
{
	int		type;
	size_t	t_i;
	size_t	c_count;

	c_count = 0;
	t_i = 0;
	while (head + t_i != tail)
	{
		type = head[t_i].type;
		if (type == LPAREN)
			t_i += match_paren(head + t_i);
		else if (type == PIPE)
			c_count++;
		t_i++;
	}
	c_count++;
	return (c_count);
}

// static int	store_cmd_unit(t_cmd *tmp, const char *src, const t_tokens *tkns, size_t *i)
// {
// 	if (tkns->data[*i].type == LPAREN)
// 		tmp->type = SUBSHELL;
// 	else
// 		tmp->type = NORMAL;
// 	tmp->words = create_words(src, tkns, i);
// 	tmp->conds = create_conds(src, tkns, i);
// 	tmp->redirects = create_redirects(src, tkns, i);
// 	if (!tmp->conds || !tmp->words || !tmp->redirects)
// 		return (0);
// 	return (1);
// }

t_cmd	*create_cmds(const char *src, const t_tkn *head, const t_tkn *tail)
{
	t_cmd	*cmds;
	size_t	c_len;
	// size_t	pipeline_i;

	c_len = count_cmds(head, tail);
	cmds = malloc(sizeof(t_cmd) * (c_len + 1));
	if (!cmds)
		return (NULL);
	(void)src;
	// pipeline_i = 0;
	// while (pipeline_i < c_len)
	// {
	// 	if (!store_cmd_unit(&cmds[pipeline_i], src, tkns, i))
	// 	{
	// 		while (pipeline_i--)
	// 		{
	// 			delete_conds(cmds[pipeline_i].conds);
	// 			delete_words(cmds[pipeline_i].words);
	// 			delete_redirects(cmds[pipeline_i].redirects);
	// 		}
	// 		return (free(cmds), NULL);
	// 	}
	// 	pipeline_i++;
	// }
	// cmds[pipeline_i].type = TAIL;
	// return (store_pipeline(src, tkns, i, cmds));
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
