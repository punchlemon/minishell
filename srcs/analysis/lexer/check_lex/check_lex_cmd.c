/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lex_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:45:29 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 16:32:26 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "check_lex.h"

#include "ft_printf.h"

static int	check_lex_subshell(const t_lex_data *lex_data, size_t *i, const size_t len)
{
	size_t	j;

	if (++(*i) >= len)
		return (0);
	j = len - 1;
	while (j > *i)
	{
		if (lex_data[j].token == RPAREN)
		{
			if (!check_lex_and_or(lex_data + *i, j - *i))
				return (0);
			*i = j + 1;
			return (1);
		}
		else if (lex_data[j].token == LPAREN)
			return (0);
		j--;
	}
	return (0);
}

static int	check_lex_io_redirect(const t_lex_data *lex_data, size_t *i,
		const size_t len)
{
	if (++(*i) >= len)
		return (0);
	return (check_lex_word(lex_data, i, len));
}

static int	check_lex_normal_cmd(const t_lex_data *lex_data, size_t *i,
		const size_t len)
{
	if (token_is_io_redirect(lex_data[*i].token))
	{
		if (!check_lex_io_redirect(lex_data, i, len))
			return (0);
	}
	else
	{
		if (!check_lex_word(lex_data, i, len))
			return (0);
	}
	return (1);
}

int	check_lex_cmd(const t_lex_data *lex_data, size_t *i, const size_t len)
{
	if (token_is_subshell(lex_data[*i].token))
	{
		if (!check_lex_subshell(lex_data, i, len))
			return (0);
		while (*i < len)
		{
			if (!token_is_io_redirect(lex_data[*i].token))
				return (1);
			else if (!check_lex_io_redirect(lex_data, i, len))
				return (0);
		}
	}
	else
	{
		if (!check_lex_normal_cmd(lex_data, i, len))
			return (0);
		while (*i < len)
		{
			if (!token_is_normal_cmd(lex_data[*i].token))
				return (1);
			else if (!check_lex_normal_cmd(lex_data, i, len))
				return (0);
		}
	}
	return (1);
}
