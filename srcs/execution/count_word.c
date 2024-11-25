/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:57:29 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/25 16:19:37 by retanaka         ###   ########.fr       */
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

void	count_word_in_a_tkn_double(t_tkn *tkn, size_t *word_len, t_env *env,
	char *st)
{
	size_t	i;
	size_t	sub;
	char	*tmp;

	i = 1;
	while (&tkn->head[i + 1] < tkn->tail)
	{
		sub = check_valiable(&tkn->head[i]);
		if (sub)
		{
			tmp = get_value(&tkn->head[i], env, st);
			if (tmp)
				*word_len += ft_strlen(tmp);
			*word_len -= sub;
			i += sub;
		}
		else
			i++;
	}
}

void	count_word_in_a_tkn_normal(t_tkn *tkn, size_t *word_len, t_env *env,
	char *st)
{
	size_t	i;
	size_t	sub;
	char	*tmp;

	i = 0;
	while (&tkn->head[i] < tkn->tail)
	{
		sub = check_valiable(&tkn->head[i]);
		if (sub)
		{
			tmp = get_value(&tkn->head[i], env, st);
			if (tmp)
				*word_len += ft_strlen(tmp);
			*word_len -= sub;
			i += sub;
		}
		else
			i++;
	}
}

void	count_word_in_a_tkn(t_tkn *tkn, size_t *word_len, t_env *env, char *st)
{
	*word_len += tkn->tail - tkn->head;
	if (tkn->type == DOUBLE)
		count_word_in_a_tkn_double(tkn, word_len, env, st);
	else if (tkn->type == NORMAL)
		count_word_in_a_tkn_normal(tkn, word_len, env, st);
	if (tkn->type == SINGLE || tkn->type == DOUBLE)
		*word_len -= 2;
}

size_t	count_word(t_tkn *tkns, t_env *env, char *st)
{
	size_t	t_i;
	size_t	word_len;
	size_t	tmp;

	word_len = 0;
	t_i = 0;
	tmp = count_tkns_for_word(tkns);
	while (t_i < tmp)
	{
		count_word_in_a_tkn(&tkns[t_i], &word_len, env, st);
		t_i++;
	}
	return (word_len);
}
