/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:52:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 23:45:50 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*lexer(const char *src)
{
	t_token	*tokens;
	size_t	tokens_count;
	size_t	i;

	tokens_count = count_tokens(src);
	if (!tokens_count)
		return (NULL);
	tokens = malloc(sizeof(t_token) * (tokens_count + 1));
	if (!tokens)
		return (NULL);
	i = 0;
	while (i < tokens_count)
		tokens[i++].type = HEAD;
	tokens[i].type = TAIL;
	store_tokens(src, tokens);
	// if (!check_tokens(tokens))
	// 	return (free(tokens), NULL);
	return (tokens);
}
