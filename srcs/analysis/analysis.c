/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:47:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/10 09:19:55 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"

t_cond	*analysis(char *src)
{
	t_tkn	*tkns;
	// t_cond	*conds;

	tkns = lexer(src);
	if (!tkns)
		return (NULL);
	print_tkns(tkns);
	if (!checker(tkns))
		return (ft_printf("minishell: syntax error\n"), NULL);
	// conds = parser(tkns);
	free(tkns);
	// if (!conds)
	// 	return (ft_printf("minishell: malloc error\n"), NULL);
	// print_conds(conds, 0);
	// return (conds);
	return (NULL);
}
