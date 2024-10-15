/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:47:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 10:04:04 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "analysis.h"
#include <stdlib.h>

t_and_or	*analysis(char *src)
{
	t_lex_data	*lex_data;
	t_and_or	*and_or;
	size_t		i;

	lex_data = lexer(src);
	if (!lex_data)
	{
		write(1, "minishell: syntax error\n", 24);
		return (NULL);
	}
	i = 0;
	while (1)
	{
		if (lex_data[i].token == END)
		{
			ft_printf("end\n");
			break ;
		}
		ft_printf("i:%d token:%d, head:%d, tail:%d\n", i, lex_data[i].token,
			(int)lex_data[i].head, (int)lex_data[i].tail);
		i++;
	}
	and_or = parser(src, lex_data);
	free(lex_data);
	return (and_or);
}
