/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_subshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:42:12 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/17 11:58:48by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_analysis.h"
#include "t_minishell.h"
#include "delete_parser.h"
#include "create_parser.h"

static size_t	count_redirects(const t_tokens *tokens, size_t i)
{
}

static t_redirect	*create_redirects(const char *src, const t_tokens *tokens,
	size_t *i, size_t redirects_count)
{
	while (*i < redirects_count)
	{
	}
}

t_subshell	*create_subshell(const char *src, const t_tokens *tokens,
	size_t *i)
{
	t_subshell	*subshell;

	subshell = malloc(sizeof(t_normal_cmd));
	if (!subshell)
		return (NULL);
	(*i)++;
	subshell->conds = create_conds(src, tokens, i);
	if (!subshell->conds)
		return (free(subshell), NULL);
	subshell->redirects
		= create_redirects(src, tokens, i, count_redirects(tokens, *i));
	if (!subshell->redirects)
		return (delere_conds(subshell->conds), free(subshell), NULL);
	return (subshell);
}
