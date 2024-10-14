/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lex_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:45:29 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/14 19:51:10 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lex_data.h"
#include "check_lex.h"

static int	check_lex_normal_cmd(const t_lex_data *lex_data, size_t *i,
		const size_t len)
{
	int	token;

	token = lex_data[*i].token;
	if (token == LESS || token == GREAT
		|| token == DLESS || token == DGREAT)
	{
		if (!check_lex_io_redirect(lex_data, i, len))
			return (0);
	}
	else
		if (!check_lex_word(lex_data, i, len))
			return (0);
	return (1);
}

static int	check_lex_loop_io_redirect(const t_lex_data *lex_data, size_t *i,
		const size_t len)
{
	int	token;

	while (*i < len)
	{
		token = lex_data[*i].token;
		if (token == LESS || token == GREAT
			|| token == DLESS || token == DGREAT)
		{
			if (!check_lex_io_redirect(lex_data, i, len))
				return (0);
		}
		else
			break ;
	}
	return (1);
}

int	check_lex_cmd(const t_lex_data *lex_data, size_t *i, const size_t len)
{
	if (lex_data[*i].token == LPAREN)
	{
		if (++(*i) >= len)
			return (0);
		if (!check_lex_subshell(lex_data, i, len))
			return (0);
		if (*i >= len)
			return (1);
		return (check_lex_loop_io_redirect(lex_data, i, len));
	}
	else
	{
		if (!check_lex_normal_cmd(lex_data, i, len))
			return (0);
		if (*i >= len)
			return (1);
		while (*i < len)
			if (!check_lex_normal_cmd(lex_data, i, len))
				return (0);
		return (1);
	}
}
