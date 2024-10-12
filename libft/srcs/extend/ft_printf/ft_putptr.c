/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:20:07 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/12 13:20:55 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_check(unsigned long long p, int *count)
{
	ft_putstr_check("0x", count);
	if (*count == -1)
		return (*count);
	ft_putnumber_check(p, 'p', count, 16);
	return (*count);
}
