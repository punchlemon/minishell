/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:20:49 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/25 16:07:14 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*ss;
	unsigned char		*dd;
	size_t				i;

	ss = (const unsigned char *)src;
	dd = (unsigned char *)dst;
	i = 0;
	if (ss > dd)
	{
		while (i < len)
		{
			dd[i] = ss[i];
			i++;
		}
	}
	else if (ss < dd)
	{
		while (0 < len)
		{
			dd[len - 1] = ss[len - 1];
			len--;
		}
	}
	return (dst);
}

// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	const unsigned char	*ss;
// 	unsigned char		*dd;
// 	unsigned char		*temp;
// 	size_t				i;

// 	if (dst == NULL && src == NULL)
// 		return (NULL);
// 	ss = (const unsigned char *)src;
// 	dd = (unsigned char *)dst;
// 	temp = (unsigned char *)malloc(sizeof(unsigned char) * (len + 1));
// 	if (temp == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		temp[i] = ss[i];
// 		i++;
// 	}
// 	i = 0;
// 	while (i < len)
// 	{
// 		dd[i] = temp[i];
// 		i++;
// 	}
// 	return (dst);
// }
