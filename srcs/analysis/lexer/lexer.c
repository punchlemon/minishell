/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:52:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/14 12:51:31 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "t_lex_data.h"

// for debug
#include "ft_printf.h"
// for debug

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

	// for debug
	ft_printf("lex_data_len:%d\n", (int)lex_data_len);
	for (int i = 0;; i++)
	{
		ft_printf("i:%d token:%d, head:%d, tail:%d\n", i, lex_data[i].token
			, (int)lex_data[i].head, (int)lex_data[i].tail);
		if (lex_data[i].token == END)
			break ;
	}
	// for debug

	if (!check_lex(lex_data))
		return (free(lex_data), NULL);
	return (lex_data);
}
