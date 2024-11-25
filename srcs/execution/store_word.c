/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:59:22 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/25 16:31:27 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "sig.h"
#include "ft_printf.h"
#include "ft_printf_stderr.h"
#include "libft.h"
#include "builtin.h"

size_t	count_tkns_for_word(t_tkn *tkns);
size_t	check_valiable(const char *src);
char	*get_value(const char *src, t_env *env, char *st);
void	count_word_in_a_tkn(t_tkn *tkn, size_t *word_len, t_env *env, char *st);

void	store_word_in_a_tkn_double(char *dst, t_tkn *tkn, t_env *env, char *st)
{
	size_t	i;
	size_t	sub;
	size_t	d_i;
	char	*tmp;

	d_i = 0;
	i = 1;
	while (&tkn->head[i + 1] < tkn->tail)
	{
		sub = check_valiable(&tkn->head[i]);
		if (sub)
		{
			tmp = get_value(&tkn->head[i], env, st);
			i += sub;
			if (!tmp)
				continue ;
			ft_memmove(&dst[d_i], tmp, ft_strlen(tmp));
			d_i += ft_strlen(tmp);
		}
		else
			dst[d_i++] = tkn->head[i++];
	}
}

void	store_word_in_a_tkn_normal(char *dst, t_tkn *tkn, t_env *env, char *st)
{
	size_t	i;
	size_t	sub;
	size_t	d_i;
	char	*tmp;

	d_i = 0;
	i = 0;
	while (&tkn->head[i] < tkn->tail)
	{
		sub = check_valiable(&tkn->head[i]);
		if (sub)
		{
			tmp = get_value(&tkn->head[i], env, st);
			i += sub;
			if (!tmp)
				continue ;
			ft_memmove(&dst[d_i], tmp, ft_strlen(tmp));
			d_i += ft_strlen(tmp);
		}
		else
			dst[d_i++] = tkn->head[i++];
	}
}

void	store_word_in_a_tkn(char *dst, t_tkn *tkn, t_env *env, char *st)
{
	if (tkn->type == DOUBLE)
		store_word_in_a_tkn_double(dst, tkn, env, st);
	else if (tkn->type == NORMAL)
		store_word_in_a_tkn_normal(dst, tkn, env, st);
	else
		ft_memmove(dst, &(tkn->head[1]), tkn->tail - tkn->head - 2);
}

void	store_word(char *dst, t_tkn *tkns, t_env *env, char *st)
{
	size_t	d_i;
	size_t	t_i;
	size_t	tmp;

	t_i = 0;
	d_i = 0;
	tmp = count_tkns_for_word(tkns);
	while (t_i < tmp)
	{
		store_word_in_a_tkn(&dst[d_i], &tkns[t_i], env, st);
		count_word_in_a_tkn(&tkns[t_i], &d_i, env, st);
		t_i++;
	}
}
