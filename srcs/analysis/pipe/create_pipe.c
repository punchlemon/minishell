/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:29:40 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 15:27:22 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include "minishell.h"

t_pipe	*create_pipe(char *src)
{
	t_pipe	*pipe;

	pipe = ft_calloc(sizeof(t_pipe));
	if (!pipe)
		return (NULL);
	pipe->cmd = create_cmd(src);
	return (pipe);
}
