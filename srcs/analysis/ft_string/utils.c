/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:25:33 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/23 16:17:50 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

int	put(char *src)
{
	if (!src)
		return (write(1, "(null)", 6));
	return (write(1, src, ft_strlen(src)));
}

int	put_len(char *src, size_t len)
{
	if (!src)
		return (write(1, "(null)", 6));
	return (write(1, src, len));
}
