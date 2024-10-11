/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_or.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:04:26 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/11 21:08:58 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"

void	print_and_or(t_and_or *and_or)
{
	size_t	i;

	if (!and_or)
		return ((void)put("and_or:(null)\n"));
	if (!and_or->pipe)
		return ((void)put("and_or->pipe:(null)\n"));
	i = 0;
	while (and_or[i].pipe)
	{
		write(1, "op:", 3);
		if (and_or[i].op == CMD)
			write(1, "cmd ", 4);
		else if (and_or[i].op == AND)
			write(1, "and ", 4);
		else if (and_or[i].op == OR)
			write(1, "or ", 3);
		i++;
	}
}

// put関数を全部ft_printfに変更する
