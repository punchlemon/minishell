/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:22:00 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/22 23:40:12 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_analysis.h"
#include "type.h"
#include "libft_extend.h"

void	store_repeat_tkn(t_tkn *tkns, const char *src, size_t *i,
			size_t *t_i)
{
	char	c;

	c = src[*i];
	(*i)++;
	if (c == '&')
		tkns[*t_i].type = AND_IF;
	else if (c == '|')
		tkns[*t_i].type = OR_IF;
	else if (c == '<')
		tkns[*t_i].type = DLESS;
	else if (c == '>')
		tkns[*t_i].type = DGREAT;
}

void	store_tkn(t_tkn *tkns, const char *src, size_t *i, size_t *t_i)
{
	char	c;

	c = src[(*i)++];
	if (c == '(')
		tkns[*t_i].type = LPAREN;
	else if (c == ')')
		tkns[*t_i].type = RPAREN;
	else if (c == src[*i])
		store_repeat_tkn(tkns, src, i, t_i);
	else if (c == '|')
		tkns[*t_i].type = PIPE;
	else if (c == '<')
		tkns[*t_i].type = LESS;
	else if (c == '>')
		tkns[*t_i].type = GREAT;
	(*t_i)++;
	while (ft_isspace(src[*i]))
		(*i)++;
}
