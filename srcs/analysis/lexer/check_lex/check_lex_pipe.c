/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lex_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:43:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 13:58:58 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "check_lex.h"

int	check_lex_pipe(const t_lex_data *lex_data, size_t *i, const size_t len)
{
	if (!check_lex_cmd(lex_data, i, len))
		return (0);
	while (*i < len)
	{
		if (lex_data[*i].token == PIPE)
		{
			if (++(*i) >= len)
				return (0);
		}
		else
			return (0);
		if (!check_lex_cmd(lex_data, i, len))
			return (0);
	}
	return (1);
}
