/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_and_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:00:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 14:06:17 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "pipe/pipe.h"
#include <stdlib.h>

void	*delete_and_or(t_and_or *and_or)
{
	size_t		i;

	i = 0;
	while (and_or[i].pipe)
	{
		and_or[i].op = 0;
		and_or[i].pipe = delete_pipe(and_or[i].pipe);
		i++;
	}
	free(and_or);
	return (NULL);
}

///　NULLを入れられることには対応していない
