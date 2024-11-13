/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:17:00 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/27 19:31:36 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ans;

	if (size != 0)
	{
		if (count > SIZE_MAX / size)
			return (NULL);
	}
	ans = (unsigned char *)malloc(size * count);
	if (ans == NULL)
		return (NULL);
	ft_bzero((void *)ans, size * count);
	return (ans);
}
