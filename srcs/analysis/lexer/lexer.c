/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:52:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 13:46:48 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lex_data	*lexer(const char *src)
{
	size_t		lex_data_len;
	t_lex_data	*lex_data;

	lex_data_len = count_lex(src);
	if (!lex_data_len)
		return (NULL);
	lex_data = malloc(sizeof(t_lex_data) * (lex_data_len + 1));
	if (!lex_data)
		return (NULL);
	store_lex(src, lex_data);
	if (!check_lex(lex_data, lex_data_len))
		return (free(lex_data), NULL);
	return (lex_data);
}
