/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:27:55 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/23 16:23:28 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <unistd.h>

int	update_cap(t_str *str)
{
	if (str->cap >= str->len + 1)
		return (0);
	while (1)
	{
		if (str->cap >= str->len + 1)
			return (1);
		if (str->cap < 1024)
			str->cap *= 2;
		else
			str->cap *= 1.25;
	}
}
