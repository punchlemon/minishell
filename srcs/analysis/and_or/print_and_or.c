/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_or.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:04:26 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/06 19:45:01 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"

void	print_and_or(t_and_or *and_or)
{
	if (!and_or)
		return ((void)put("and_or:(null)\n"));
	if (!and_or->pipe)
		return ((void)put("and_or->pipe:(null)\n"));
	while (and_or)
	{
		put("op:");
		if (and_or->op == CMD)
			put("cmd");
		else if (and_or->op == AND)
			put("and");
		else if (and_or->op == OR)
			put("or");
		put(" ");
		// put_str_arr(and_or->pipe->str_s);
		// put_char_ppも実装するべき
		and_or = and_or->next;
	}
}
