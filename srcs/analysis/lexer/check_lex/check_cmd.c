/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:45:29 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/17 17:08:15 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "check_lex.h"

#include "ft_printf.h"

static int	check_subshell(const t_tokens *tokens, size_t *i)
{
	size_t		j;
	t_tokens	tmp_tokens;

	if (++(*i) >= tokens->len)
		return (0);
	j = tokens->len - 1;
	while (j > *i)
	{
		if (tokens->data[j].type == RPAREN)
		{
			tmp_tokens.data = tokens->data + *i;
			tmp_tokens.len = j - *i;
			if (!check_and_or(&tmp_tokens))
				return (0);
			*i = j + 1;
			return (1);
		}
		else if (tokens->data[j].type == LPAREN)
			return (0);
		j--;
	}
	return (0);
}

static int	check_io_redirect(const t_tokens *tokens, size_t *i)
{
	if (++(*i) >= tokens->len)
		return (0);
	return (check_word(tokens, i));
}

static int	check_normal_cmd(const t_tokens *tokens, size_t *i)
{
	if (type_is_io_redirect(tokens->data[*i].type))
	{
		if (!check_io_redirect(tokens, i))
			return (0);
	}
	else
	{
		if (!check_word(tokens, i))
			return (0);
	}
	return (1);
}

int	check_cmd(const t_tokens *tokens, size_t *i)
{
	if (type_is_subshell(tokens->data[*i].type))
	{
		if (!check_subshell(tokens, i))
			return (0);
		while (*i < tokens->len)
		{
			if (!type_is_io_redirect(tokens->data[*i].type))
				return (1);
			else if (!check_io_redirect(tokens, i))
				return (0);
		}
	}
	else
	{
		if (!check_normal_cmd(tokens, i))
			return (0);
		while (*i < tokens->len)
		{
			if (!type_is_normal_cmd(tokens->data[*i].type))
				return (1);
			else if (!check_normal_cmd(tokens, i))
				return (0);
		}
	}
	return (1);
}
