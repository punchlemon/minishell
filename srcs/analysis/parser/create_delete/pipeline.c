/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:04:44 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 17:04:16 by retanaka         ###   ########.fr       */
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

static int	store_cmd_unit(t_cmd_unit *tmp, const char *src, const t_tokens *tokens, size_t *i)
{
	if (tokens->data[*i].type == LPAREN)
		tmp->type = SUBSHELL;
	else
		tmp->type = NORMAL;
	tmp->words = create_words(src, tokens, i);
	tmp->conds = create_conds(src, tokens, i);
	tmp->redirects = create_redirects(src, tokens, i);
	if (!tmp->conds || !tmp->words || !tmp->redirects)
		return (0);
	return (1);
}

t_cmd_unit	*create_pipeline(const char *src, const t_tokens *tokens, size_t *i)
{
	t_cmd_unit	*pipeline;
	size_t		pipeline_count;
	size_t		pipeline_i;

	pipeline_count = count_pipeline(tokens, *i);
	pipeline = malloc(sizeof(t_cmd_unit) * (pipeline_count + 1));
	if (!pipeline)
		return (NULL);
	pipeline_i = 0;
	while (pipeline_i < pipeline_count)
	{
		if (!store_cmd_unit(&pipeline[pipeline_i], src, tokens, i))
		{
			while (pipeline_i--)
			{
				delete_conds(pipeline[pipeline_i].conds);
				delete_words(pipeline[pipeline_i].words);
				delete_redirects(pipeline[pipeline_i].redirects);
			}
			return (free(pipeline), NULL);
		}
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
		delete_conds(pipeline[i].conds);
		delete_words(pipeline[i].words);
		delete_redirects(pipeline[i].redirects);
		i++;
	}
	free(pipeline);
}
