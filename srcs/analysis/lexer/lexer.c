/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:52:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 23:08:33 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_tokens	*lexer(const char *src)
{
	t_tokens	*tokens;

	tokens = malloc(sizeof(t_tokens));
	if (!tokens)
		return (NULL);
	tokens->len = count_lex(src);
	if (!tokens->len)
		return (free(tokens), NULL);
	tokens->data = malloc(sizeof(t_token) * (tokens->len + 1));
	if (!tokens->data)
		return (free(tokens), NULL);
	store_lex(src, tokens);
	if (!check_lex(tokens))
		return (free(tokens->data), free(tokens), NULL);
	return (tokens);
}
