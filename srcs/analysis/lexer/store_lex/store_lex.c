/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_lex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:56:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 14:00:12 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "store_lex.h"
#include "libft_extend.h"

#include "ft_printf.h"

void	store_lex(const char *src, t_lex_data *lex_data)
{
	size_t	i;
	size_t	lex_data_i;

	lex_data_i = 0;
	i = 0;
	while (ft_isspace(src[i]))
		i++;
	while (src[i])
	{
		if (ft_istoken(src[i]))
			store_token(lex_data, src, &i, &lex_data_i);
		else
			store_word(lex_data, src, &i, &lex_data_i);
		if (!src[i])
			break ;
	}
	lex_data[lex_data_i].token = END;
}
