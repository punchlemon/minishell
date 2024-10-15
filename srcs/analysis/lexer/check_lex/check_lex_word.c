/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lex_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:45:25 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 16:37:49 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "check_lex.h"

#include "ft_printf.h"

int	check_lex_word(const t_lex_data *lex_data, size_t *i, const size_t len)
{
	if (!token_is_word(lex_data[(*i)++].token))
		return (0);
	while (*i < len)
	{
		if (!token_is_word(lex_data[*i].token))
			break ;
		if (lex_data[*i].head - lex_data[*i - 1].tail == 1)
			(*i)++;
		else
			break ;
	}
	return (1);
}
