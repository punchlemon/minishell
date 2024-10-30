/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:47:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/30 21:56:42 by hnakayam         ###   ########.fr       */
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
		return (ft_printf("minishell: malloc error\n"), NULL);
	if (!check_conds(tkns, t_end))
		return (ft_printf("minishell: syntax error\n"), NULL);
	conds = parser(src, tkns, t_end);
	free(tkns);
	if (!conds)
		return (ft_printf("minishell: malloc error\n"), NULL);
	return (conds);
}
