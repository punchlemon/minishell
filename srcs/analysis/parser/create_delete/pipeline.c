/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:04:44 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 10:52:21 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_delete.h"

static size_t	count_pipeline(const t_tokens *tokens, size_t i)
{
	int		type;
	size_t	cmd_unit_count;

	cmd_unit_count = 1;
	while (i < tokens->len)
	{
		type = tokens->data[i].type;
		if (type == LPAREN)
		{
			while (tokens->data[i].type != RPAREN)
				i++;
		}
		else if (type == RPAREN || type == AND_IF || type == OR_IF)
			break ;
		else if (type == PIPE)
			cmd_unit_count++;
		i++;
	}
	return (cmd_unit_count);
}

static void	delete_cmd_unit(t_cmd_unit cmd_unit)
{
	if (cmd_unit.type == SUBSHELL)
		delete_conds(cmd_unit.conds);
	else if (cmd_unit.type == NORMAL)
		delete_words(cmd_unit.words);
	delete_redirects(cmd_unit.redirects);
}

static t_cmd_unit	*store_pipeline(const char *src, const t_tokens *tokens,
	size_t *i, t_cmd_unit *pipeline)
{
	size_t		pipeline_i;
	t_cmd_unit	*tmp;

	pipeline_i = 0;
	while (pipeline[pipeline_i].type != TAIL)
	{
		tmp = &pipeline[pipeline_i];
		if (tokens->data[*i].type == LPAREN)
		{
			tmp->type = SUBSHELL;
			tmp->conds = create_conds(src, tokens, i);
			tmp->words = NULL;
		}
		else
			tmp->words = create_words(src, tokens, i);
		tmp->redirects = create_redirects(src, tokens, i);
		if ((!tmp->conds && !tmp->words) || tmp->redirects)
		{
			while (pipeline_i--)
				delete_cmd_unit(pipeline[pipeline_i]);
			return (free(pipeline), NULL);
		}
		pipeline_i++;
	}
	return (pipeline);
}

t_cmd_unit	*create_pipeline(const char *src, const t_tokens *tokens, size_t *i)
{
	t_cmd_unit	*pipeline;
	t_cmd_unit	*tmp;
	size_t		pipeline_count;
	size_t		pipeline_i;

	pipeline_count = count_pipeline(tokens, *i);
	pipeline = malloc(sizeof(t_cmd_unit) * (pipeline_count + 1));
	if (!pipeline)
		return (NULL);
	pipeline_i = 0;
	while (pipeline_i < pipeline_count)
	{
		tmp = &pipeline[pipeline_i];
		tmp->conds = NULL;
		tmp->type = NORMAL;
		pipeline_i++;
	}
	pipeline[pipeline_i].type = TAIL;
	return (store_pipeline(src, tokens, i, pipeline));
}

void	delete_pipeline(t_cmd_unit *pipeline)
{
	size_t	i;

	i = 0;
	while (pipeline[i].type != TAIL)
	{
		delete_cmd_unit(pipeline[i]);
		i++;
	}
	free(pipeline);
}
