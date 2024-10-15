/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_or.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:04:26 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 14:07:46 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "and_or.h"
#include "ft_printf.h"
#include <stdlib.h>

void	print_and_or(t_and_or *and_or)
{
	size_t	i;

	if (!and_or)
		return ((void)ft_printf("and_or:(null)\n"));
	if (!and_or->pipe)
		return ((void)ft_printf("and_or->pipe:(null)\n"));
	i = 0;
	while (and_or[i].pipe)
	{
		ft_printf("op:");
		if (and_or[i].op == CMD)
			ft_printf("cmd ");
		else if (and_or[i].op == AND)
			ft_printf("and ");
		else if (and_or[i].op == OR)
			ft_printf("or ");
		i++;
	}
}

// put関数を全部ft_printfに変更する
