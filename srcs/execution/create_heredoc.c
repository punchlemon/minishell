/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:34:17 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/25 15:35:10 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "sig.h"
#include "ft_printf.h"
#include "ft_printf_stderr.h"
#include "libft.h"
#include "builtin.h"

size_t	count_tkns_for_word(t_tkn *tkns);

size_t	count_heredoc(t_tkn *tkns, size_t t_len)
{
	size_t	t_i;
	size_t	tmp;
	size_t	len;

	len = 0;
	t_i = 0;
	while (t_i < t_len)
	{
		tmp = tkns[t_i].tail - tkns[t_i].head;
		if (tkns[t_i].type == DOUBLE || tkns[t_i].type == SINGLE)
			tmp -= 2;
		len += tmp;
		t_i++;
	}
	return (len);
}

size_t	store_heredoc(t_red *red, t_tkn *tkns, size_t t_len)
{
	size_t	t_i;
	size_t	tmp;
	size_t	len;

	len = 0;
	t_i = 0;
	while (t_i < t_len)
	{
		tmp = tkns[t_i].tail - tkns[t_i].head;
		if (tkns[t_i].type == DOUBLE || tkns[t_i].type == SINGLE)
		{
			tmp -= 2;
			red->type = NO_EX_DLESS;
			ft_memmove(&((red->target)[len]), &(tkns[t_i].head[1]), tmp);
		}
		else
			ft_memmove(&((red->target)[len]), tkns[t_i].head, tmp);
		len += tmp;
		t_i++;
	}
	return (len);
}

int	create_heredoc(t_red *red, t_tkn *tkns)
{
	size_t	len;
	size_t	t_len;

	len = 0;
	t_len = count_tkns_for_word(tkns);
	len = count_heredoc(tkns, t_len);
	red->target = ft_xcalloc(sizeof(char) * (len + 1));
	if (!(red->target))
		return (0);
	store_heredoc(red, tkns, t_len);
	(red->target)[len] = '\0';
	return (1);
}
