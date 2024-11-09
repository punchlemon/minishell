/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:52:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/08 19:53:45 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_tkn	*lexer(const char *src)
{
	t_tkn	*tkns;
	size_t	i;
	size_t	t_len;

	i = 0;
	while (ft_isspace(src[i]))
		i++;
	if (!src[i])
		return (NULL);
	t_len = count_t_len(&src[i]);
	if (!t_len)
		return (ft_printf("minishell: syntax error\n"), NULL);
	tkns = malloc(sizeof(t_tkn) * (t_len + 1));
	if (!tkns)
		return (ft_printf("minishell: malloc error\n"), NULL);
	store_tkns(&src[i], tkns);
	return (tkns);
}
