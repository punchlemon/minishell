/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:47:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 23:52:11 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "ft_printf.h"

t_cond	*analysis(char *src)
{
	t_token	*tokens;
	// t_cond	*conds;

	tokens = lexer(src);
	if (!tokens)
		return (ft_printf("minishell: syntax error\n"), NULL);
	print_tokens(tokens);
	// conds = parser(src, tokens);
	// print_conds(conds);
	free(tokens);
	return (NULL);/////
	// return (conds);
}
// mallocの失敗とsyntax errorが混同している
