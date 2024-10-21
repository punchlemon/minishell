/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:45:29 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 23:59:13 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_tokens.h"

#include "ft_printf.h"

static int	check_subshell(const t_token *tokens, size_t *i)
{
	size_t	j;

	if (tokens[++(*i)].type == TAIL)
		return (0);
	j = check_tokens(tokens + *i);
	if (!j)
		return (0);
	*i += j;
	return (1);
}

static int	check_redirect(const t_token *tokens, size_t *i)
{
	if (tokens[++(*i)].type == TAIL)
		return (0);
	return (check_word(tokens, i));
}

static int	check_normal(const t_token *tokens, size_t *i)
{
	if (type_is_redirect(tokens[*i].type))
	{
		if (!check_redirect(tokens, i))
			return (0);
	}
	else
	{
		if (!check_word(tokens, i))
			return (0);
	}
	return (1);
}

int	check_cmd(const t_token *tokens, size_t *i)
{
	if (type_is_subshell(tokens[*i].type))
	{
		if (!check_subshell(tokens, i))
			return (0);
		while (tokens[*i].type != TAIL)
		{
			if (!type_is_redirect(tokens[*i].type))
				return (1);
			else if (!check_redirect(tokens, i))
				return (0);
		}
	}
	else
	{
		if (!check_normal(tokens, i))
			return (0);
		while (tokens[*i].type != TAIL)
		{
			if (!type_is_normal(tokens[*i].type))
				return (1);
			else if (!check_normal(tokens, i))
				return (0);
		}
	}
	return (1);
}
