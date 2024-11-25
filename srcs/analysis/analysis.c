/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:47:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/25 14:37:05 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "ft_printf_stderr.h"

t_cond	*analysis(char *src)
{
	t_tkn	*tkns;
	t_cond	*conds;

	tkns = lexer(src);
	if (!tkns)
		return (NULL);
	if (!checker(tkns))
		return (ft_printf_stderr("minishell: syntax error\n"), NULL);
	conds = parser(tkns);
	free(tkns);
	if (!conds)
		return (ft_printf_stderr("minishell: malloc error\n"), NULL);
	return (conds);
}
