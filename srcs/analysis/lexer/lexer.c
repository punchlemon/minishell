/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:52:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/12 14:29:33 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "ft_printf.h"
#include "libft.h"
#include "libft_extend.h"
#include <stdlib.h>

int	ft_istoken(const char c)
{
	return (c == '&' || c == '|'
		|| c == '(' || c == ')'
		|| c == '<' || c == '>');
}

size_t	*lexer(const char *src)
{
	size_t	len;
	size_t	*lex_data;

	len = count_lex(src);
	if (!len)
		return (NULL);
	lex_data = ft_calloc(sizeof(int) * (len + 1));
	if (!lex_data)
		return (NULL);
	store_lex(lex_data, src);
	if (!check_lex(lex_data))
		return (free(lex_data), NULL);
	ft_printf("check_lex is finished!\n");
	return (lex_data);
}
