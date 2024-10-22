/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:47:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/22 23:44:38 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "ft_printf.h"

t_cond	*analysis(char *src)
{
	t_tkn	*tkns;
	t_cond	*conds;

	tkns = lexer(src);
	if (!tkns)
		return (ft_printf("minishell: syntax error\n"), NULL);
	print_tokens(tkns);
	conds = parser(src, tkns);
	print_conds(conds);
	free(tkns);
	return (conds);
}
// mallocの失敗とsyntax errorが混同している
