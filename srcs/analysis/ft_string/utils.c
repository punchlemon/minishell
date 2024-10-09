/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:25:33 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 14:00:00 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
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
