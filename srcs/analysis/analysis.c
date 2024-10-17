/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:47:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/17 13:05:50 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "analysis.h"
#include <stdlib.h>

void	print_tokens(t_tokens *tokens)
{
	size_t		i;

	i = 0;
	while (i < tokens->len)
	{
		ft_printf("i:%u type:%d, head:%u, tail:%u\n",
			(unsigned int)i,
			tokens->data[i].type,
			(unsigned int)tokens->data[i].head,
			(unsigned int)tokens->data[i].tail);
		i++;
	}
}

void	print_conds(t_cond *conds)
{
	size_t		i;

	i = 0;
	// while (i < tokens->len)
	// {
	// 	ft_printf("i:%u type:%d, head:%u, tail:%u\n",
	// 		(unsigned int)i,
	// 		tokens->data[i].type,
	// 		(unsigned int)tokens->data[i].head,
	// 		(unsigned int)tokens->data[i].tail);
	// 	i++;
	// }
}

t_cond	*analysis(char *src)
{
	t_tokens	*tokens;
	t_cond		*conds;

	tokens = lexer(src);
	if (!tokens)
		return (ft_printf("minishell: syntax error\n"), NULL);
	conds = parser(src, tokens);
	free(tokens);
	return (conds);
}
