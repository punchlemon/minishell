/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:05:36 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/10 09:06:19 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"

int	check_word(const t_tkn *tkns, size_t *t_i)
{
	if (!type_is_word(tkns[*t_i].type))
		return (0);
	(*t_i)++;
	while (type_is_word(tkns[*t_i].type))
	{
		if ((tkns[*t_i].head - tkns[*t_i - 1].tail) > 1)
			return (1);
		(*t_i)++;
	}
	return (1);
}

int	check_cmd(const t_tkn *tkns, size_t	*t_i)
{
	if (type_is_red(tkns[*t_i].type))
		(*t_i)++;
	return (check_word(tkns, t_i));
}

static int	check_cmds(const t_tkn *tkns, size_t *t_i)
{
	if (!type_is_cmd(tkns[*t_i].type))
		return (0);
	while (type_is_cmd(tkns[*t_i].type))
		if (!check_cmd(tkns, t_i))
			return (0);
	return (1);
}

static int	check_cond(const t_tkn *tkns, size_t *t_i)
{
	if (!check_cmds(tkns, t_i))
		return (0);
	while (!type_is_and_or(tkns[*t_i].type) && tkns[*t_i].type != TAIL)
	{
		if (tkns[(*t_i)++].type != PIPE)
			return (0);
		if (!check_cmds(tkns, t_i))
			return (0);
	}
	return (1);
}

int	checker(const t_tkn *tkns)
{
	size_t	t_i;

	t_i = 0;
	if (!check_cond(tkns, &t_i))
		return (0);
	while (tkns[t_i].type != TAIL)
	{
		if (!type_is_and_or(tkns[t_i++].type))
			return (0);
		if (!check_cond(tkns, &t_i))
			return (0);
	}
	return (1);
}
