/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:53:59 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/29 16:55:57 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "create.h"

static size_t	count_word_len(const t_tkn *tkns, const size_t t_len)
{
	size_t	w_len;
	size_t	t_i;

	w_len = tkns->tail - tkns->head;
	t_i = 1;
	while (t_i < t_len)
	{
		w_len += tkns[t_i].tail - tkns[t_i].head;
		t_i++;
	}
	return (w_len);
}

static void	store_word(char *word, const char *src, const t_tkn *tkns,
	const size_t t_len)
{
	size_t		w_i;
	const t_tkn	*now;
	size_t		t_i;
	size_t		tmp_len;

	w_i = tkns->tail - tkns->head;
	ft_memmove(word, &src[tkns->head], w_i);
	t_i = 1;
	while (t_i < t_len)
	{
		now = &tkns[t_i];
		tmp_len = now->tail - now->head;
		ft_memmove(&word[w_i], &src[now->head], tmp_len);
		w_i += tmp_len;
		t_i++;
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
