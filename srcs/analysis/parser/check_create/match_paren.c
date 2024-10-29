/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_paren.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:29:43 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/28 21:54:58 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_delete.h"

size_t	match_paren(const t_tkn *tkns)
{
	size_t	i;

	i = 1;
	while (tkns[i].type != RPAREN)
	{
		if (tkns[i].type == LPAREN)
			i += match_paren(&tkns[i]);
		i++;
	}
	return (i);
}
