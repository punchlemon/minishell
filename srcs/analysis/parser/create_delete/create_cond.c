/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cond.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:04:44 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/17 13:39:51 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_analysis.h"
#include "t_minishell.h"
#include "delete_parser.h"

static size_t	count_cmds(const t_tokens *tokens, size_t *i)
{
	int		type;
	size_t	cmd_unit_count;

	cmd_unit_count = 1;
	while (*i < tokens->len)
	{
		type = tokens->data[*i].type;
		if (type == LPAREN)
		{
			while (tokens->data[*i].type != RPAREN)
				(*i)++;
		}
		else if (type == RPAREN || type == AND_IF || type == OR_IF)
			break ;
		else if (type == PIPE)
			cmd_unit_count++;
		(*i)++;
	}
	return (cmd_unit_count);
}

static int	create_cmd_unit(const char *src, const t_tokens *tokens, size_t *i,
	t_cmd_unit *cmd_unit)
{
	if (tokens->data[*i].type == LPAREN)
	{
		cmd_unit->type = SUBSHELL;
		cmd_unit->subshell = create_subshell(src, tokens, i);
		cmd_unit->normal_cmd = NULL;
		if (!cmd_unit->subshell)
			return (0);
	}
	else
	{
		cmd_unit->type = NORMAL_CMD;
		cmd_unit->subshell = NULL;
		cmd_unit->normal_cmd = create_normal_cmd(src, tokens, i);
		if (!cmd_unit->normal_cmd)
			return (0);
	}
	return (1);
}

static void	delete_cmd_unit(t_cmd_unit *cmd_unit)
{
	if (cmd_unit->type == SUBSHELL)
		delete_subshell(cmd_unit->subshell);
	else if (cmd_unit->type == NORMAL_CMD)
		delete_normal_cmd(cmd_unit->normal_cmd);
}

static t_cmd_unit	*store_pipeline(const char *src, const t_tokens *tokens,
	size_t *i, t_cmd_unit *pipeline)
{
	size_t	pipeline_i;

	pipeline_i = 0;
	while (pipeline[pipeline_i].type != TAIL)
	{
		if (!create_cmd_unit(src, tokens, i, pipeline + pipeline_i))
		{
			while (pipeline_i--)
				delete_cmd_unit(pipeline + pipeline_i);
			return (free(pipeline), NULL);
		}
		pipeline_i++;
	}
	return (pipeline);
}

t_cmd_unit	*create_pipeline(const char *src, const t_tokens *tokens, size_t *i)
{
	t_cmd_unit	*pipeline;
	size_t		cmds_count;

	cmds_count = count_cmds(tokens, i);
	pipeline = malloc(sizeof(t_cmd_unit) * (cmds_count + 1));
	if (!pipeline)
		return (0);
	pipeline[cmds_count].type = TAIL;
	return (store_pipeline(src, tokens, i, pipeline));
}
