/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:45:25 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 23:39:12 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "check_lex.h"

#include "ft_printf.h"

int	check_word(const t_tokens *tokens, size_t *i)
{
	if (!type_is_word(tokens->data[(*i)++].type))
		return (0);
	while (*i < tokens->len)
	{
		if (!type_is_word(tokens->data[*i].type))
			break ;
		if (tokens->data[*i].head - tokens->data[*i - 1].tail == 1)
			(*i)++;
		else
			break ;
	}
	return (1);
}
