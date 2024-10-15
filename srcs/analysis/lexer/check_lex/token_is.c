/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:54:00 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 15:55:23 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"

int	token_is_word(int token)
{
	return (token == NORMAL || token == SINGLE || token == DOUBLE);
}

int	token_is_subshell(int token)
{
	return (token == LPAREN);
}

int	token_is_io_redirect(int token)
{
	return (token == LESS || token == GREAT
		|| token == DLESS || token == DGREAT);
}

int token_is_normal_cmd(int token)
{
	return (token_is_io_redirect(token) || token_is_word(token));
}

int	token_is_cmd(int token)
{
	return (token_is_subshell(token) || token_is_normal_cmd(token));
}
