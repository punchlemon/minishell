/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:14:57 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/15 17:17:20 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (s)
	{
		len = 0;
		while (s[len])
			len++;
		write(fd, s, len);
		write(fd, "\n", 1);
	}
	else
		write(fd, "(null)\n", 7);
}
