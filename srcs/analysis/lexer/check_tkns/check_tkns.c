/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tkns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:05:36 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/22 23:35:30 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_tkns.h"

#include "ft_printf.h"

static int	check_pipe(const t_tkn *tkns, size_t *i)
{
	if (!check_cmd(tkns, i))
		return (0);
	while (tkns[*i].type != TAIL)
	{
		if (tkns[*i].type != PIPE)
			return (1);
		(*i)++;
		if (tkns[*i].type == TAIL)
			return (0);
		if (!type_is_cmd(tkns[*i].type) || !check_cmd(tkns, i))
			return (0);
	}
	return (1);
}

int	check_tokens(const t_tkn *tkns)
{
	size_t	i;

	i = 0;
	if (!type_is_cmd(tkns[i].type))
		return (0);
	if (!check_pipe(tkns, &i))
		return (0);
	while (tkns[i].type != TAIL)
	{
		if (tkns[i].type != AND_IF && tkns[i].type != OR_IF)
			return (i);
		i++;
		if (tkns[i].type == TAIL)
			return (0);
		if (!type_is_cmd(tkns[i].type) || !check_pipe(tkns, &i))
			return (0);
	}
	return (1);
}
