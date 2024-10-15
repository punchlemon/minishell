/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lex_subshell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:45:28 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 10:00:24 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lex_data.h"
#include "check_lex.h"

#include "ft_printf.h"

int	check_lex_subshell(const t_lex_data *lex_data, size_t *i, const size_t len)
{
	size_t	j;

	j = len - 1;
	while (j > *i)
	{
		if (lex_data[j].token == RPAREN)
		{
			if (!check_lex_and_or(lex_data + *i, j - *i))
				return (0);
			*i = j + 1;
			return (1);
		}
		else if (lex_data[j].token == LPAREN)
			return (0);
		j--;
	}
	return (0);
}
