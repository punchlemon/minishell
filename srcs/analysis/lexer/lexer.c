/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:52:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/29 01:26:04 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

#include "../analysis.h"

t_tkn	*lexer(const char *src, size_t *tkns_len)
{
	t_tkn	*tkns;
	size_t	i;

	*tkns_len = count_tkns(src);
	if (!*tkns_len)
		return (NULL);
	tkns = malloc(sizeof(t_tkn) * (*tkns_len + 1));
	if (!tkns)
		return (NULL);
	i = 0;
	while (i < *tkns_len)
		tkns[i++].type = HEAD;
	tkns[i].type = TAIL;
	store_tkns(src, tkns);
	if (!check_tkns(tkns, *tkns_len))
		return (free(tkns), NULL);
	return (tkns);
}
