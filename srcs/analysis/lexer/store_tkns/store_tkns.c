/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tkns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:56:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/02 21:59:44 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_analysis.h"
#include "type.h"
#include "libft_extend.h"
#include "store_tkns.h"

#include "ft_printf.h"

static void	store_quote(t_tkn *tkns, const char *src, size_t *i)
{
	char	c;

	c = src[*i];
	if (c == '\'')
		tkns->type = SINGLE;
	else
		tkns->type = DOUBLE;
	tkns->head = (*i)++;
	while (src[*i] != c)
		(*i)++;
		/// if encounter null char, you have to end
	tkns->tail = ++(*i);
	c = src[*i];
	while (ft_isspace(src[*i]))
		(*i)++;
}

static void	store_normal_word(t_tkn *tkns, const char *src, size_t *i)
{
	char	c;

	tkns->type = NORMAL;
	tkns->head = *i;
	while (1)
	{
		c = src[++(*i)];
		if (ft_istoken(c) || !c)
			return ((void)(tkns->tail = *i));
		else if (c == '"' || c == '\'')
		{
			tkns->tail = *i;
			store_quote(tkns, src, i);
			return ;
		}
	}
}
void	store_tkns(const char *src, t_tkn *tkns)
{
	size_t	i;
	size_t	t_i;

	t_i = 0;
	i = 0;
	while (ft_isspace(src[i]))
		i++;
	while (src[i])
	{
		if (ft_istoken(src[i]))
			store_tkn(&tkns[t_i], src, &i);
		else
		{
			if (src[i] == '"' || src[i] == '\'')
				store_quote(&tkns[t_i], src, &i);
			else
				store_normal_word(&tkns[t_i], src, &i);
		}
		t_i++;
		while (ft_isspace(src[i]))
			i++;
	}
	tkns[i].type = TAIL;
}
