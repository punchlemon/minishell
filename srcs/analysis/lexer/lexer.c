/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:52:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/24 15:08:28 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "ft_printf_stderr.h"

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
		return (ft_printf_stderr("minishell: syntax error\n"), NULL);
	tkns = ft_xcalloc(sizeof(t_tkn) * (t_len + 1));
	store_tkns(&src[i], tkns);
	return (tkns);
}
