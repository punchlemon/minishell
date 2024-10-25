/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:53:34 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/25 20:25:29 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_delete.h"

t_red	*create_reds(const char *src, const t_tkn *head, const t_tkn *tail)
{
	(void)src;
	(void)head;
	(void)tail;
	return (NULL);
}

void	delete_reds(t_red *reds)
{
	size_t	i;

	if (!reds)
		return ;
	i = 0;
	while (reds[i].type != TAIL)
		free(reds[i++].target);
	free(reds);
}
