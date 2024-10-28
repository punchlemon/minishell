/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:47:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/29 00:19:40 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "ft_printf.h"

t_cond	*analysis(char *src)
{
	t_tkn	*tkns;
	size_t	tkns_len;
	t_cond	*conds;

	tkns = lexer(src, &tkns_len);
	if (!tkns)
		return (ft_printf("minishell: syntax error\n"), NULL);
	print_tkns(tkns);
	conds = parser(src, tkns, tkns_len);
	print_conds(conds, 0);
	free(tkns);
	return (conds);
}
// mallocの失敗とsyntax errorが混同している
