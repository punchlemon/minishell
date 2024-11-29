/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:47:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/29 22:47:06 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "t_minishell.h"
#include "ft_printf_stderr.h"

int	limit_pipe(t_tkn *tkns)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (tkns[i].type != TAIL)
	{
		if (tkns[i].type == AND_IF || tkns[i].type == OR_IF)
			count = 0;
		else if (tkns[i].type == PIPE)
			count++;
		if (count > 3332)
			return (1);
		i++;
	}
	return (0);
}

t_cond	*analysis(char *src)
{
	t_tkn	*tkns;
	t_cond	*conds;

	tkns = lexer(src);
	if (!tkns)
		return (NULL);
	if (limit_pipe(tkns))
	{
		ft_printf_stderr("minishell: syntax error near unexpected token `|'\n");
		return (NULL);
	}
	if (!checker(tkns))
		return (ft_printf_stderr("minishell: syntax error\n"), NULL);
	conds = parser(tkns);
	free(tkns);
	if (!conds)
		return (ft_printf_stderr("minishell: malloc error\n"), NULL);
	return (conds);
}
