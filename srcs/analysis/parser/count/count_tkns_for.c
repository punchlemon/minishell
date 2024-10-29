/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tkns_for.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:28:45 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/29 17:01:33 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_analysis.h"
#include "type.h"

size_t	count_tkns_for_cond(const t_tkn *tkns, const size_t t_end)
{
	size_t	t_i;

	t_i = 0;
	while (t_i < t_end && !type_is_and_or(tkns[t_i].type))
	{
		if (tkns[t_i].type == LPAREN)
			t_i += match_paren(&tkns[t_i]);
		t_i++;
	}
	return (t_i);
}

size_t	count_tkns_for_cmd(const t_tkn *tkns, const size_t t_end)
{
	size_t	t_i;

	t_i = 0;
	if (tkns[t_i].type == LPAREN)
		t_i += match_paren(tkns) + 1;
	while (t_i < t_end && tkns[t_i].type != PIPE)
		t_i++;
	return (t_i);
}

size_t	count_tkns_for_word(const t_tkn *tkns, const size_t t_end)
{
	const t_tkn	*now;
	size_t		t_i;

	t_i = 1;
	while (t_i < t_end)
	{
		now = &tkns[t_i];
		if (now->type == SINGLE || now->type == DOUBLE)
		{
			if (now->head - tkns[t_i - 1].tail == 1)
			{
				t_i++;
			}
			else
				break ;
		}
		else
			break ;
	}
	return (t_i);
}
// single doubleがあった後にnormalが来ても大丈夫なように修正する
