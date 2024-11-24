/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xcalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:58:43 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/24 15:05:53 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_xcalloc(size_t n)
{
	char	*res;

	res = malloc(n);
	if (res == NULL)
		exit(1);
	while (n--)
		res[n] = 0;
	return ((void *)res);
}
