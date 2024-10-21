/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:45:25 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 21:53:06 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_tokens.h"

#include "ft_printf.h"

int	check_word(const t_token *tokens, size_t *i)
{
	if (!type_is_word(tokens[(*i)++].type))
		return (0);
	while (tokens[*i].type !=TAIL)
	{
		if (!type_is_word(tokens[*i].type))
			break ;
		if (tokens[*i].head - tokens[*i - 1].tail == 1)
			(*i)++;
		else
			break ;
	}
	return (1);
}
