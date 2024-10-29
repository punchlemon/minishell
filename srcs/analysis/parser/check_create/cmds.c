/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:04:44 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/28 21:48:42 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_delete.h"

t_cmd	*create_cmds(const char *src, const t_tkn *tkns, const size_t t_len)
{
	t_cmd	*cmds;
	size_t	c_len;

	c_len = count_cmds(tkns, t_len);
	cmds = malloc(sizeof(t_cmd) * (c_len + 1));
	if (!cmds)
		return (NULL);
	if (!store_cmds(cmds, src, tkns, t_len))
		return (NULL);
	return (cmds);
}

void	delete_cmds(t_cmd *cmds)
{
	size_t	i;

	i = 0;
	while (cmds[i].type != TAIL)
	{
		if (cmds[i].type == SUBSHELL)
			delete_conds(cmds[i].conds);
		else
			delete_words(cmds[i].words);
		delete_reds(cmds[i].reds);
		i++;
	}
	free(cmds);
}
