/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lex_and_or.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:42:52 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 16:37:12 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "check_lex.h"

#include "ft_printf.h"

int	check_lex_and_or(const t_lex_data *lex_data, const size_t len)
{
	size_t	i;

	i = 0;
	if (!token_is_cmd(lex_data[i].token) || !check_lex_pipe(lex_data, &i, len))
		return (0);
	while (i < len)
	{
		if (((lex_data[i].token != AND_IF) && (lex_data[i].token != OR_IF))
			|| ++i >= len)
			return (0);
		if (!token_is_cmd(lex_data[i].token)
			|| !check_lex_pipe(lex_data, &i, len))
			return (0);
	}
	return (1);
}
