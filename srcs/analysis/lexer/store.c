/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tkns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:56:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/02 22:15:43by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

size_t	store_repeat_tkn(t_tkn *tkns, const char *src)
{
	char	c;

	c = src[0];
	if (c == '&')
		tkns->type = AND_IF;
	else if (c == '|')
		tkns->type = OR_IF;
	else if (c == '<')
		tkns->type = DLESS;
	else if (c == '>')
		tkns->type = DGREAT;
	return (2);
}

size_t	store_tkn(t_tkn *tkns, const char *src)
{
	char	c;

	c = src[0];
	tkns->head = NULL;
	tkns->tail = NULL;
	if (c == '(')
		tkns->type = LPAREN;
	else if (c == ')')
		tkns->type = RPAREN;
	else if (c == src[1])
		return (store_repeat_tkn(tkns, &src[1]));
	else if (c == '|')
		tkns->type = PIPE;
	else if (c == '<')
		tkns->type = LESS;
	else if (c == '>')
		tkns->type = GREAT;
	return (1);
}

static size_t	store_quote(t_tkn *tkns, const char *src)
{
	char	c;
	size_t	i;

	i = 0;
	c = src[i];
	if (c == '\'')
		tkns->type = SINGLE;
	else
		tkns->type = DOUBLE;
	tkns->head = &src[i];
	i++;
	while (src[i] != c)
		i++;
	i++;
		/// if encounter null char, you have to end
	tkns->tail = &src[i];
	return (i);
}

static size_t	store_normal_word(t_tkn *tkns, const char *src)
{
	size_t	i;

	i = 0;
	tkns->type = NORMAL;
	tkns->head = &src[i];
	while (ft_isnormal_word(src[i]))
		i++;
	tkns->tail = &src[i];
	return (i);
}

void	store_tkns(const char *src, t_tkn *tkns)
{
	size_t	i;
	size_t	t_i;
	size_t	tmp;

	t_i = 0;
	i = 0;
	while (src[i])
	{
		if (ft_istoken(src[i]))
			tmp = store_tkn(&tkns[t_i], &src[i]);
		else if (ft_isquote(src[i]))
			tmp = store_quote(&tkns[t_i], &src[i]);
		else
			tmp = store_normal_word(&tkns[t_i], &src[i]);
		i += tmp;
		t_i++;
		while (ft_isspace(src[i]))
			i++;
	}
	tkns[t_i].type = TAIL;
}
