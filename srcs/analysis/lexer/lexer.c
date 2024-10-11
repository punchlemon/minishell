/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:52:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/11 21:02:17 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extend.h"
#include <stdlib.h>

int	ft_istoken(const char c)
{
	return (c == '&' || c == '|'
		|| c == '(' || c == ')'
		|| c == '<' || c == '>');
}

int	*lexer(const char *src)
{
	size_t	len;
	int		*lex_data;

	len = count_lex(src);
	if (!len)
		return (NULL);
	lex_data = ft_calloc(sizeof(int) * (len + 1));
	store_lex(lex_data, src);
	if (!check_lex(lex_data))
		return (free(lex_data), NULL);
	return (lex_data);
}
