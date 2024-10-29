/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:52:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/29 11:03:37 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

#include "../analysis.h"

t_tkn	*lexer(const char *src, size_t *t_len)
{
	t_tkn	*tkns;
	size_t	i;

	*t_len = count_tkns(src);
	if (!*t_len)
		return (NULL);
	tkns = malloc(sizeof(t_tkn) * (*t_len + 1));
	if (!tkns)
		return (NULL);
	i = 0;
	while (i < *t_len)
		tkns[i++].type = HEAD;
	tkns[i].type = TAIL;
	store_tkns(src, tkns);
	return (tkns);
}
