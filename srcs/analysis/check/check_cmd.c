/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:45:29 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/30 12:49:42 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	check_word(const t_tkn *tkns, const size_t t_end)
{
	size_t		t_i;

	if (!type_is_word(tkns->type))
		return (0);
	t_i = 1;
	while (t_i < t_end)
	{
		if (!type_is_word(tkns[t_i].type))
			return (1);
		if (tkns[t_i].head - tkns[t_i - 1].tail == 1)
			t_i++;
		else
			break ;
	}
	return (1);
}

static int	check_subshell(const t_tkn *tkns, const size_t t_end)
{
	size_t	t_i;
	size_t	tmp;

	tmp = match_paren(tkns, t_end);
	if (!check_conds(&tkns[1], tmp - 1))
		return (0);
	t_i = tmp;
	while (t_i < (t_end - 1))
	{
		if (!type_is_redirect(tkns[t_i++].type))
			return (0);
		tmp += count_tkns_for_word(&tkns[t_i], t_end - t_i);
		if (!check_word(&tkns[t_i], tmp))
			return (0);
		t_i += tmp;
	}
	return (1);
}

static int	check_normal(const t_tkn *tkns, const size_t t_end)
{
	size_t	t_i;
	size_t	tmp;

	t_i = 0;
	if (type_is_redirect(tkns[t_i].type))
	{
		t_i++;
		tmp = count_tkns_for_word(&tkns[t_i], t_end - t_i);
		if (!check_word(&tkns[t_i], tmp))
			return (0);
		t_i += tmp;
	}
	else
	{
		tmp = count_tkns_for_word(&tkns[t_i], t_end - t_i);
		if (!check_word(&tkns[t_i], tmp))
			return (0);
		t_i += tmp;
	}
	if (t_i < t_end)
		return (check_normal(&tkns[t_i], t_end - t_i));
	return (1);
}

int	check_cmd(const t_tkn *tkns, const size_t t_end)
{
	if (tkns->type == LPAREN)
	{
		if (!check_subshell(tkns, t_end))
			return (0);
	}
	else if (type_is_normal(tkns->type))
	{
		if (!check_normal(tkns, t_end))
			return (0);
	}
	else
		return (0);
	return (1);
}
