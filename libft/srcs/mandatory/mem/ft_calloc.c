/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:59:26 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 15:10:23 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t n)
{
	unsigned char	*p;

	p = malloc(sizeof(unsigned char) * n);
	if (!p)
		return (NULL);
	while (n--)
		p[n] = 0;
	return ((void *)p);
}
