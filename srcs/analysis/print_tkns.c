/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tkns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:45:03 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/05 09:05:07 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "ft_printf.h"

void	print_tkns(t_tkn *tkns)
{
	size_t	i;

	i = 0;
	while (tkns[i].type != TAIL)
	{
		ft_printf("i:%u type:%d, len:%u\n", i, tkns[i].type,
			tkns[i].tail - tkns[i].head);
		i++;
	}
}
