/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_normal_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:41:17 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/17 12:41:08 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_analysis.h"
#include "t_minishell.h"

static size_t	count_words_and_redirects(const t_tokens *tokens, size_t i,
	size_t *words_count, size_t *redirects_count)
{
}

static char	**create_words(const char *src, const t_tokens *tokens, size_t i,
	size_t words_count)
{
}

static t_redirect	*create_redirects(const char *src, const t_tokens *tokens,
	size_t i, size_t redirects_count)
{

}

t_normal_cmd	*create_normal_cmd(const char *src, const t_tokens *tokens,
	size_t *i)
{
	size_t			words_count;
	size_t			redirects_count;
	size_t			end;
	t_normal_cmd	*normal_cmd;

	normal_cmd = malloc(sizeof(t_normal_cmd));
	if (!normal_cmd)
		return (NULL);
	end = count_words_and_redirects(tokens, *i, &words_count, &redirects_count);
	normal_cmd->words = create_words(src, tokens, *i, words_count);
	if (!normal_cmd->words)
		return (free(normal_cmd), NULL);
	normal_cmd->redirects = create_redirects(src, tokens, *i, redirects_count);
	if (!normal_cmd->redirects)
		return (delete_words(normal_cmd->words), free(normal_cmd), NULL);
	*i = end;
	return (normal_cmd);
}
