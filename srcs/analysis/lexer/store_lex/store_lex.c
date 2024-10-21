/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_lex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:56:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 14:57:17 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_analysis.h"
#include "type.h"
#include "libft_extend.h"
#include "store_lex.h"

#include "ft_printf.h"

void	store_lex(const char *src, t_tokens *tokens)
{
	size_t	i;
	size_t	t_i;

	t_i = 0;
	i = 0;
	while (ft_isspace(src[i]))
		i++;
	while (src[i])
	{
		if (ft_istoken(src[i]))
			store_token(tokens, src, &i, &t_i);
		else
			store_word(tokens, src, &i, &t_i);
		if (!src[i])
			break ;
	}
	tokens->data[t_i].type = TAIL;
}
