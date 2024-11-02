/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tkn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:22:00 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/02 21:36:51 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_analysis.h"
#include "type.h"
#include "libft_extend.h"

void	store_repeat_tkn(t_tkn *tkns, const char *src, size_t *i)
{
	char	c;

	c = src[*i];
	(*i)++;
	if (c == '&')
		tkns->type = AND_IF;
	else if (c == '|')
		tkns->type = OR_IF;
	else if (c == '<')
		tkns->type = DLESS;
	else if (c == '>')
		tkns->type = DGREAT;
}

void	store_tkn(t_tkn *tkns, const char *src, size_t *i)
{
	char	c;

	c = src[(*i)++];
	if (c == '(')
		tkns->type = LPAREN;
	else if (c == ')')
		tkns->type = RPAREN;
	else if (c == src[*i])
		store_repeat_tkn(tkns, src, i);
	else if (c == '|')
		tkns->type = PIPE;
	else if (c == '<')
		tkns->type = LESS;
	else if (c == '>')
		tkns->type = GREAT;
	tkns->head = 0;
	tkns->tail = 0;
	while (ft_isspace(src[*i]))
		(*i)++;
}
