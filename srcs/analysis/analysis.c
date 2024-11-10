/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:47:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/09 15:27:16 by hnakayam         ###   ########.fr       */
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
	print_conds(conds, 0);
	free(tkns);
	if (!conds)
		return (ft_printf("minishell: malloc error\n"), NULL);
	return (conds);
}
