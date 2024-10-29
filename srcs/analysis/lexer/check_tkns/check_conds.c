/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:05:36 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/29 10:42:19 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_conds.h"

static int	check_cond(const t_tkn *tkns, const size_t t_len)
{
	size_t	t_i;
	size_t	tmp;

	if (!type_is_cmd(tkns->type))
		return (0);
	tmp = 0;
	while (tkns[tmp].type != PIPE)
		tmp++;
	if (!check_cmd(tkns, t_i))
		return (0);
	t_i = tmp;
	while (t_i < t_len)
	{
		if (tkns[t_i++].type != PIPE)
			return (0);
		if (!type_is_cmd(tkns[t_i].type) || !check_cmd(tkns, t_i))
			return (0);
	}
	return (1);
}

int	check_conds(const t_tkn *tkns, const size_t t_len)
{
	size_t	t_i;
	size_t	tmp;

	tmp = 0;
	while (!type_is_and_or(tkns[tmp].type) && tmp < t_len)
		tmp++;
	if (!check_cond(tkns, tmp))
		return (0);
	t_i = tmp;
	while (t_i < t_len - 1)
	{
		if (!type_is_and_or(tkns[t_i++].type))
			return (0);
		tmp = 0;
		while (!type_is_and_or(tkns[t_i + tmp].type) && (t_i + tmp) < t_len)
			tmp++;
		if (!check_cond(tkns, tmp))
			return (0);
		t_i += tmp;
	}
	return (1);
}

/// lenで終了状態を管理する
/// check_subshellがcheck_tknsを呼び出した時にはTAILで終了できないため
