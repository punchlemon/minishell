/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:24:22 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/19 07:15:32 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bb;
	size_t			i;

	bb = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		bb[i] = c;
		i++;
	}
	return (b);
}
