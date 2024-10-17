/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_conds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:38:19 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/17 13:09:25 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"

void	delete_subshell(t_subshell *subshell)
{
	delete_conds(subshell->conds);
	delete_redirects(subshell->redirects);
	free(subshell);
}

void	delete_normal_cmd(t_normal_cmd *normal_cmd)
{
	size_t	i;

	i = 0;
	while (normal_cmd->words[i])
		free(normal_cmd->words[i++]);
	free(normal_cmd->words);
	delete_redirects(normal_cmd->redirects);
	free(normal_cmd);
}

void	delete_cond(t_cond *cond)
{
	size_t		i;
	t_cmd_unit	cmd_unit;

	i = 0;
	while (cond[i].type != TAIL)
	{
		cmd_unit = cond->pipeline[i];
		if (cmd_unit.type == SUBSHELL)
			delete_subshell(cmd_unit.subshell);
		else if (cmd_unit.type == NORMAL_CMD)
			delete_normal_cmd(cmd_unit.normal_cmd);
		i++;
	}
	free(cond->pipeline);
}

void	delete_conds(t_cond *conds)
{
	size_t	i;

	i = 0;
	while (conds[i].type != TAIL)
	{
		delete_cond(conds + i);
		i++;
	}
	free(conds);
}
