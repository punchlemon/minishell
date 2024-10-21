/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:22:00 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 23:19:18 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_analysis.h"
#include "type.h"
#include "libft_extend.h"

void	store_repeat_token(t_token *tokens, const char *src, size_t *i,
			size_t *t_i)
{
	char	c;

	c = src[*i];
	(*i)++;
	if (c == '&')
		tokens[*t_i].type = AND_IF;
	else if (c == '|')
		tokens[*t_i].type = OR_IF;
	else if (c == '<')
		tokens[*t_i].type = DLESS;
	else if (c == '>')
		tokens[*t_i].type = DGREAT;
}

void	store_token(t_token *tokens, const char *src, size_t *i, size_t *t_i)
{
	char	c;

	c = src[(*i)++];
	if (c == '(')
		tokens[*t_i].type = LPAREN;
	else if (c == ')')
		tokens[*t_i].type = RPAREN;
	else if (c == src[*i])
		store_repeat_token(tokens, src, i, t_i);
	else if (c == '|')
		tokens[*t_i].type = PIPE;
	else if (c == '<')
		tokens[*t_i].type = LESS;
	else if (c == '>')
		tokens[*t_i].type = GREAT;
	(*t_i)++;
	while (ft_isspace(src[*i]))
		(*i)++;
}
