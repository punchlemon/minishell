/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tkns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:56:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/22 23:41:44 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_analysis.h"
#include "type.h"
#include "libft_extend.h"
#include "store_tkns.h"

#include "ft_printf.h"

void	store_tkns(const char *src, t_tkn *tkns)
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
			store_tkn(tkns, src, &i, &t_i);
		else
			store_word(tkns, src, &i, &t_i);
		if (!src[i])
			break ;
	}
	tkns[i].type = TAIL;
}
