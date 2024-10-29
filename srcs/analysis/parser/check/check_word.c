/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:45:25 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/29 16:51:32 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

#include "ft_printf.h"

int	check_word(const t_tkn *tkns, size_t *i)
{
	if (!type_is_word(tkns[(*i)++].type))
		return (0);
	while (tkns[*i].type != TAIL)
	{
		if (!type_is_word(tkns[*i].type))
			break ;
		if (tkns[*i].head - tkns[*i - 1].tail == 1)
			(*i)++;
		else
			break ;
	}
	return (1);
}
