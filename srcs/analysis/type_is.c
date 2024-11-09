/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:54:00 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/09 13:44:41 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"

int	type_is_word(int type)
{
	return (type == NORMAL || type == SINGLE || type == DOUBLE);
}

int	type_is_red(int type)
{
	return (type == LESS || type == GREAT || type == DLESS || type == DGREAT);
}

int	type_is_cmd(int type)
{
	return (type_is_red(type) || type_is_word(type));
}

int	type_is_cmds(int type)
{
	return (type_is_cmd(type) || type == PIPE);
}

int	type_is_and_or(int type)
{
	return (type == AND_IF || type == OR_IF);
}
