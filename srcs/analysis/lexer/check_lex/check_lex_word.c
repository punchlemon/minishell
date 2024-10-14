/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lex_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:45:25 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 01:18:30 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lex_data.h"
#include "check_lex.h"

#include "ft_printf.h"

int	check_lex_word(const t_lex_data *lex_data, size_t *i, const size_t len)
{
	int	token;

	token = lex_data[(*i)++].token;
	if (token != NORMAL && token != SINGLE && token != DOUBLE)
		return (0);
	while (*i < len)
	{
		token = lex_data[*i].token;
		if (token != NORMAL && token != SINGLE && token != DOUBLE)
			break ;
		else if (lex_data[*i].head - lex_data[*i - 1].tail == 1)
			(*i)++;
		else
			break ;
	}
	return (1);
}
