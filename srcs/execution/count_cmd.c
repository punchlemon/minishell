/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:30:07 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/25 15:30:24 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "sig.h"
#include "ft_printf.h"
#include "ft_printf_stderr.h"
#include "libft.h"
#include "builtin.h"

size_t	count_tkns_for_word(t_tkn *tkns)
{
	size_t	i;

	i = 1;
	while (tkns[i].type != TAIL && !type_is_red(tkns[i].type))
	{
		if (tkns[i].head - tkns[i - 1].tail)
			return (i);
		i++;
	}
	return (i);
}

void	count_cmd(size_t *words_len, size_t *reds_len, t_tkn *tkns)
{
	size_t	t_i;

	*words_len = 0;
	*reds_len = 0;
	t_i = 0;
	while (tkns[t_i].type != TAIL)
	{
		if (type_is_red(tkns[t_i].type))
		{
			(*reds_len)++;
			t_i++;
		}
		else
			(*words_len)++;
		t_i += count_tkns_for_word(&tkns[t_i]);
	}
}
