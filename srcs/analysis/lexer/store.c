/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:56:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/06 15:00:56y retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

size_t	store_tkn(t_tkn *tkns, const char *src)
{
	tkns->head = NULL;
	tkns->tail = NULL;
	if (src[0] == src[1])
	{
		if (src[0] == '&')
			tkns->type = AND_IF;
		else if (src[0] == '|')
			tkns->type = OR_IF;
		else if (src[0] == '<')
			tkns->type = DLESS;
		else if (src[0] == '>')
			tkns->type = DGREAT;
		return (2);
	}
	else if (src[0] == '|')
		tkns->type = PIPE;
	else if (src[0] == '<')
		tkns->type = LESS;
	else if (src[0] == '>')
		tkns->type = GREAT;
	return (1);
}

static size_t	store_quote(t_tkn *tkns, const char *src)
{
	size_t	i;

	if (src[0] == '\'')
		tkns->type = SINGLE;
	else
		tkns->type = DOUBLE;
	tkns->head = src;
	i = 1;
	while (src[i] != src[0])
		i++;
	i++;
	tkns->tail = &src[i];
	return (i);
}

static size_t	store_normal_word(t_tkn *tkns, const char *src)
{
	size_t	i;

	i = 0;
	tkns->type = NORMAL;
	tkns->head = &src[i];
	while (ft_isnormal(src[i]))
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
