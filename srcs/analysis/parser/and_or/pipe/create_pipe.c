/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:29:40 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 14:04:19 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "cmd/cmd.h"

t_pipe	*create_pipe(char *src)
{
	t_pipe	*pipe;

	pipe = ft_calloc(sizeof(t_pipe));
	if (!pipe)
		return (NULL);
	pipe->cmd = create_cmd(src);
	return (pipe);
}
