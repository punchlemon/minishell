/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:05:36 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/05 08:19:54 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

static int	check_cond(const t_tkn *tkns, const size_t t_end)
{
	size_t	t_i;
	size_t	tmp;

	tmp = count_tkns_for_cmd(tkns, t_end);
	if (!check_cmd(tkns, tmp))
		return (0);
	t_i = tmp;
	while (t_i < t_end)
	{
		if (tkns[t_i++].type != PIPE)
			return (0);
		if (t_i >= t_end)
			return (0);
		tmp = count_tkns_for_cmd(&tkns[t_i], t_end - t_i);
		if (!check_cmd(&tkns[t_i], tmp))
			return (0);
		t_i += tmp;
	}
	return (1);
}

int	check_conds(const t_tkn *tkns, const size_t t_end)
{
	size_t	t_i;
	size_t	tmp;

	tmp = count_tkns_for_cond(tkns, t_end);
	if (!check_cond(tkns, tmp))
		return (0);
	t_i = tmp;
	while (t_i < (t_end - 1))
	{
		if (!type_is_and_or(tkns[t_i++].type))
			return (0);
		tmp = count_tkns_for_cond(&tkns[t_i], t_end - t_i);
		if (!check_cond(&tkns[t_i], tmp))
			return (0);
		t_i += tmp;
	}
	return (1);
}
