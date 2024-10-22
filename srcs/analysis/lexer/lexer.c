/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:52:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/22 23:33:30 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

#include "../analysis.h"

t_tkn	*lexer(const char *src)
{
	t_tkn	*tkns;
	size_t	tokens_count;
	size_t	i;

	tokens_count = count_tokens(src);
	if (!tokens_count)
		return (NULL);
	tkns = malloc(sizeof(t_tkn) * (tokens_count + 1));
	if (!tkns)
		return (NULL);
	i = 0;
	while (i < tokens_count)
		tkns[i++].type = HEAD;
	tkns[i].type = TAIL;
	store_tokens(src, tkns);
	if (!check_tokens(tkns))
		return (free(tkns), NULL);
	return (tkns);
}
