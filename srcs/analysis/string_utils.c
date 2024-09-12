/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:27:55 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/12 17:03:35 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(char *src)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	return (i);
}

int	update_cap(size_t len, size_t *cap)
{
	if (*cap >= len)
		return (0);
	if (*cap == 0)
		*cap = 1;
	while (1)
	{
		if (*cap >= len)
			return (1);
		if (*cap < 1024)
			*cap *= 2;
		else
			*cap *= 1.25;
	}
}
