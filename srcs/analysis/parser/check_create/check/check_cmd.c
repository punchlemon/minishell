/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:45:29 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/29 08:45:29 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_conds.h"

static int	check_subshell(const t_tkn *tkns, size_t *i)
{
	size_t	j;

	if (tkns[++(*i)].type == TAIL)
		return (0);
	j = check_tkns(tkns + *i);
	if (!j)
		return (0);
	*i += j;
	return (1);
}

static int	check_redirect(const t_tkn *tkns, size_t *i)
{
	if (tkns[++(*i)].type == TAIL)
		return (0);
	return (check_word(tkns, i));
}

static int	check_normal(const t_tkn *tkns, size_t *i)
{
	if (type_is_redirect(tkns[*i].type))
	{
		if (!check_redirect(tkns, i))
			return (0);
	}
	else
	{
		if (!check_word(tkns, i))
			return (0);
	}
	return (1);
}
////// a(a)のようなコマンドが通過してしまっている

int	check_cmd(const t_tkn *tkns, size_t *i)
{
	if (type_is_subshell(tkns[*i].type))
	{
		if (!check_subshell(tkns, i))
			return (0);
		while (tkns[*i].type != TAIL)
		{
			if (!type_is_redirect(tkns[*i].type))
				return (1);
			else if (!check_redirect(tkns, i))
				return (0);
		}
	}
	else
	{
		if (!check_normal(tkns, i))
			return (0);
		while (tkns[*i].type != TAIL)
		{
			if (!type_is_normal(tkns[*i].type))
				return (1);
			else if (!check_normal(tkns, i))
				return (0);
		}
	}
	return (1);
}
