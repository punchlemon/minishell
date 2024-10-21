/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:43:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/17 17:08:39 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "check_lex.h"

#include "ft_printf.h"

int	check_pipe(const t_tokens *tokens, size_t *i)
{
	if (!check_cmd(tokens, i))
		return (0);
	while (*i < tokens->len)
	{
		if (tokens->data[*i].type != PIPE)
			return (1);
		if (++(*i) >= tokens->len)
			return (0);
		if (!type_is_cmd(tokens->data[*i].type)
			|| !check_cmd(tokens, i))
			return (0);
	}
	return (1);
}
