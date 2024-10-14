/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:47:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/14 20:01:36 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "analysis.h"
#include <stdlib.h>

t_and_or	*analysis(char *src)
{
	t_lex_data	*lex_data;
	t_and_or	*and_or;

	lex_data = lexer(src);
	if (!lex_data)
		return (NULL);


	// for debug
	// ft_printf("lex_data_len:%d\n", (int)lex_data_len);
	for (int i = 0;; i++)
	{
		if (lex_data[i].token == END)
		{
			ft_printf("end\n");
			break ;
		}
		ft_printf("i:%d token:%d, head:%d, tail:%d\n", i, lex_data[i].token
			, (int)lex_data[i].head, (int)lex_data[i].tail);
	}

	and_or = parser(src, lex_data);
	free(lex_data);
	return (and_or);
}
