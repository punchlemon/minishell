/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_and_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:00:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 12:20:13 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*delete_and_or(t_and_or *and_or)
{
	t_and_or	*next;

	while (and_or)
	{
		next = and_or->next;
		and_or->op = 0;
		and_or->pipe = delete_pipe(and_or->pipe);
		and_or->next = NULL;
		free(and_or);
		and_or = next;
	}
	return (NULL);
}
