/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:53:59 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/30 01:43:18 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "create.h"

static size_t	count_word_len(const t_tkn *tkns, const size_t t_len)
{
	size_t	w_len;
	size_t	t_i;

	w_len = tkns->tail - tkns->head;
	if (tkns->type != NORMAL)
		w_len -= 2;
	t_i = 1;
	while (t_i < t_len)
	{
		w_len += tkns[t_i].tail - tkns[t_i].head;
		if (tkns[t_i].type != NORMAL)
			w_len -= 2;
		t_i++;
	}
	return (w_len);
}

static void	store_word(char *word, const char *src, const t_tkn *tkns,
	const size_t t_len)
{
	size_t	w_i;
	size_t	t_i;
	size_t	tmp_len;

	w_i = tkns->tail - tkns->head;
	if (tkns->type != NORMAL)
	{
		w_i -= 2;
		ft_memmove(word, &src[tkns->head + 1], w_i);
	}
	else
		ft_memmove(word, &src[tkns->head], w_i);
	t_i = 0;
	while (++t_i < t_len)
	{
		tmp_len = tkns[t_i].tail - tkns[t_i].head;
		if (tkns[t_i].type != NORMAL)
		{
			tmp_len -= 2;
			ft_memmove(&word[w_i], &src[tkns[t_i].head + 1], tmp_len);
		}
		else
			ft_memmove(&word[w_i], &src[tkns[t_i].head], tmp_len);
		w_i += tmp_len;
	}
}

char	*create_word(const char *src, const t_tkn *tkns, const size_t t_len)
{
	char	*word;
	size_t	w_len;

	w_len = count_word_len(tkns, t_len);
	word = malloc(w_len + 1);
	if (!word)
		return (NULL);
	store_word(word, src, tkns, t_len);
	return (word);
}
