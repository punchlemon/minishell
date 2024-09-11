/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:37:47 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/11 16:37:48 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "string.h"

void	delete_pp(char **src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		free(src[i]);
		i++;
	}
	free(src);
}

void	exe(char **srcs)
{
	size_t	i;
	char	c;

	i = 0;
	while (srcs[i])
	{
		c = i + '0';
		write(1, &c, 1);
		write(1, ": ", 2);
		write(1, srcs[i], ft_strlen(srcs[i]));
		write(1, "\n", 1);
		i++;
	}
	delete_pp(srcs);
}
