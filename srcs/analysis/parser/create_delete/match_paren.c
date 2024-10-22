/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_paren.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:29:43 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/22 23:33:09 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_delete.h"

size_t	match_paren(const t_tkn *tokens)
{
	int		type;
	size_t	i;

	i = 1;
	while (1)
	{
		type = tokens[i].type;
		if (type == LPAREN)
			i += match_paren(tokens + i);
		else if (type == RPAREN)
			break ;
		i++;
	}
	return (i);
}
