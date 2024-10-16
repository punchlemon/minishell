/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:54:00 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 23:45:13 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"

int	type_is_word(int type)
{
	return (type == NORMAL || type == SINGLE || type == DOUBLE);
}

int	type_is_subshell(int type)
{
	return (type == LPAREN);
}

int	type_is_io_redirect(int type)
{
	return (type == LESS || type == GREAT
		|| type == DLESS || type == DGREAT);
}

int	type_is_normal_cmd(int type)
{
	return (type_is_io_redirect(type) || type_is_word(type));
}

int	type_is_cmd(int type)
{
	return (type_is_subshell(type) || type_is_normal_cmd(type));
}
