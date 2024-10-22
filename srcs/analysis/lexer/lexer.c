/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:52:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/23 01:05:45 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

#include "../analysis.h"

t_tkn	*lexer(const char *src)
{
	t_tkn	*tkns;
	size_t	tkns_count;
	size_t	i;

	tkns_count = count_tkns(src);
	if (!tkns_count)
		return (NULL);
	tkns = malloc(sizeof(t_tkn) * (tkns_count + 1));
	if (!tkns)
		return (NULL);
	i = 0;
	while (i < tkns_count)
		tkns[i++].type = HEAD;
	tkns[i].type = TAIL;
	store_tkns(src, tkns);
	if (!check_tkns(tkns))
		return (free(tkns), NULL);
	return (tkns);
}
