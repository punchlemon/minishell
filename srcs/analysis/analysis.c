/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:47:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/24 13:59:29 by hnakayam         ###   ########.fr       */
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
	// print_tkns(tkns);
	if (!checker(tkns))
		return (ft_printf_stderr("minishell: syntax error\n"), NULL);
	conds = parser(tkns);
	free(tkns);
	if (!conds)
		return (ft_printf_stderr("minishell: malloc error\n"), NULL);
	// print_conds(conds);
	return (conds);
}
