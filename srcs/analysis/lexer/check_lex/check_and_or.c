/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_or.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:42:52 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 23:46:03 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "check_lex.h"

#include "ft_printf.h"

int	check_and_or(const t_tokens *tokens)
{
	size_t	i;

	i = 0;
	if (!type_is_cmd(tokens->data[i].type)
		|| !check_pipe(tokens, &i))
		return (0);
	while (i < tokens->len)
	{
		if (((tokens->data[i].type != AND_IF)
				&& (tokens->data[i].type != OR_IF)) || ++i >= tokens->len)
			return (0);
		if (!type_is_cmd(tokens->data[i].type) || !check_pipe(tokens, &i))
			return (0);
	}
	return (1);
}
