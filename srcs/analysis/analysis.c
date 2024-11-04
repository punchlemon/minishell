/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:47:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/05 08:14:06 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "ft_printf.h"

t_cond	*analysis(char *src)
{
	t_tkn	*tkns;
	size_t	t_end;
	t_cond	*conds;

	tkns = lexer(src, &t_end);
	if (!tkns)
		return (NULL);
	if (!check_conds(tkns, t_end))
		return (ft_printf("minishell: syntax error\n"), NULL);
	conds = parser(tkns, t_end);
	free(tkns);
	if (!conds)
		return (ft_printf("minishell: malloc error\n"), NULL);
	return (conds);
}
