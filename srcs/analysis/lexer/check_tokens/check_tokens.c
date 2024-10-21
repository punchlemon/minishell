/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:05:36 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 23:33:46 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_tokens.h"

#include "ft_printf.h"

static int	check_pipe(const t_token *tokens, size_t *i)
{
	if (!check_cmd(tokens, i))
		return (0);
	while (tokens[*i].type != TAIL)
	{
		if (tokens[*i].type != PIPE)
			return (1);
		(*i)++;
		if (tokens[*i].type == TAIL)
			return (0);
		if (!type_is_cmd(tokens[*i].type) || !check_cmd(tokens, i))
			return (0);
	}
	return (1);
}

int	check_tokens(const t_token *tokens)
{
	size_t	i;

	i = 0;
	if (!type_is_cmd(tokens[i].type))
		return (0);
	if (!check_pipe(tokens, &i))
		return (0);
	while (tokens[i].type != TAIL)
	{
		if (tokens[i].type != AND_IF && tokens[i].type != OR_IF)
			return (i);
		i++;
		if (tokens[i].type == TAIL)
			return (0);
		if (!type_is_cmd(tokens[i].type) || !check_pipe(tokens, &i))
			return (0);
	}
	return (1);
}
