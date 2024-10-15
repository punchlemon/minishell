/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:22:00 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 14:00:23 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "libft_extend.h"

void	store_repeat_token(t_lex_data *lex_data, const char *src, size_t *i
	, size_t *lex_data_i)
{
	char	c;

	c = src[*i];
	(*i)++;
	if (c == '&')
		lex_data[*lex_data_i].token = AND_IF;
	else if (c == '|')
		lex_data[*lex_data_i].token = OR_IF;
	else if (c == '<')
		lex_data[*lex_data_i].token = DLESS;
	else if (c == '>')
		lex_data[*lex_data_i].token = DGREAT;
}

void	store_token(t_lex_data *lex_data, const char *src, size_t *i
	, size_t *lex_data_i)
{
	char	c;

	c = src[(*i)++];
	if (c == '(')
		lex_data[*lex_data_i].token = LPAREN;
	else if (c == ')')
		lex_data[*lex_data_i].token = RPAREN;
	else if (c == src[*i])
		store_repeat_token(lex_data, src, i, lex_data_i);
	else if (c == '|')
		lex_data[*lex_data_i].token = PIPE;
	else if (c == '<')
		lex_data[*lex_data_i].token = LESS;
	else if (c == '>')
		lex_data[*lex_data_i].token = GREAT;
	(*lex_data_i)++;
	while (ft_isspace(src[*i]))
		(*i)++;
}
