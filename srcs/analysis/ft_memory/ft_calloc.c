/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:59:26 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/01 16:20:12 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <stdlib.h>

void	*ft_calloc(size_t n)
{
	void	*p;

	p = malloc(n);
	if (!p)
		return (NULL);
	ft_memzero(p, n);
	return (p);
}
