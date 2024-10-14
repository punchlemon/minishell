/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:05:36 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/14 16:39:07 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lex_data.h"

static int check_lex_pipe(t_lex_data *lex_data, size_t *i)
{
	int		token;

	if (!check_lex_cmd(lex_data, i))
		return (0);
	while (lex_data[*i].token != END)
	{
		if (lex_data[*i].token == PIPE)
			(*i)++;
		else
			return (0);
		if (!check_lex_cmd(lex_data, i))
			return (0);
	}
	return (1);
}

static int check_lex_and_or(t_lex_data *lex_data)
{
	int		token;
	size_t	i;

	if (!check_lex_pipe(lex_data, &i))
		return (0);
	while (lex_data[i].token != END)
	{
		if (lex_data[i].token == AND_IF || lex_data[i].token == OR_IF)
			i++;
		else
			return (0);
		if (!check_lex_pipe(lex_data, &i))
			return (0);
	}
	return (1);
}

int	check_lex(t_lex_data *lex_data)
{
	return (check_lex_and_or(lex_data));
}
