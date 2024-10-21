/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:53:34 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 15:10:53 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_delete.h"

t_redirect	*create_redirects(const char *src, const t_tokens *tokens, size_t i)
{
}

void	delete_redirects(t_redirect *redirects)
{
	size_t	i;

	if (!redirects)
		return ;
	i = 0;
	while (redirects[i].type != TAIL)
		free(redirects[i++].target);
	free(redirects);
}
