/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tkns_for.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:28:45 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/30 12:37:54 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_analysis.h"
#include "type.h"

size_t	match_paren(const t_tkn *tkns, const size_t	t_end)
{
	size_t	t_i;

	t_i = 1;
	while (t_i < t_end)
	{
		if (tkns[t_i].type == LPAREN)
			t_i += match_paren(&tkns[t_i], t_end - t_i);
		else if (tkns[t_i].type == RPAREN)
			return (t_i);
		t_i++;
	}
	return (0);
}
// const size_t t_endの考え方を導入する

size_t	count_tkns_for_word(const t_tkn *tkns, const size_t t_end)
{
	size_t	t_i;

	t_i = 1;
	while (t_i < t_end)
	{
		if (!type_is_word(tkns[t_i].type))
			return (t_i);
		if (tkns[t_i].head == tkns[t_i - 1].tail)
			t_i++;
		else
			break ;
	}
	return (t_i);
}

size_t	count_tkns_for_cond(const t_tkn *tkns, const size_t t_end)
{
	size_t	t_i;

	t_i = 0;
	while (t_i < t_end && !type_is_and_or(tkns[t_i].type))
	{
		if (tkns[t_i].type == LPAREN)
			t_i += match_paren(&tkns[t_i], t_end);
		t_i++;
	}
	return (t_i);
}

size_t	count_tkns_for_cmd(const t_tkn *tkns, const size_t t_end)
{
	size_t	t_i;

	t_i = 0;
	if (tkns[t_i].type == LPAREN)
		t_i += match_paren(tkns, t_end) + 1;
	while (t_i < t_end && tkns[t_i].type != PIPE)
		t_i++;
	return (t_i);
}

////ここに書かれている関数はcheck関数にも使われるのでもう少しガードをするべき
