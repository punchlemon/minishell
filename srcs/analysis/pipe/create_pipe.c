/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:29:40 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 12:26:23 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include "minishell.h"

t_pipe	*create_pipe(t_str *str)
{
	t_pipe	*pipe;

	pipe = ft_calloc(sizeof(t_pipe));
	if (!pipe)
		return (NULL);
	pipe->cmd = create_cmd(str);
	return (pipe);
}
