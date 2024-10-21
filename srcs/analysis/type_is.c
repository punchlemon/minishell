/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:54:00 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 21:46:24 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

int	type_is_word(int type)
{
	return (type == NORMAL || type == SINGLE || type == DOUBLE);
}

int	type_is_subshell(int type)
{
	return (type == LPAREN);
}

int	type_is_redirect(int type)
{
	return (type == LESS || type == GREAT
		|| type == DLESS || type == DGREAT);
}

int	type_is_normal(int type)
{
	return (type_is_redirect(type) || type_is_word(type));
}

int	type_is_cmd(int type)
{
	return (type_is_subshell(type) || type_is_normal(type));
}
