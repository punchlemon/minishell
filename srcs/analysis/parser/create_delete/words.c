/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:16:17 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/29 00:39:32 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_delete.h"
#include "ft_printf.h"

size_t	count_word(const t_tkn *tkns, const size_t t_len)
{
	const t_tkn	*now;
	size_t		t_i;

	t_i = 1;
	while (t_i < t_len)
	{
		now = &tkns[t_i];
		if (now->type == SINGLE || now->type == DOUBLE)
		{
			if (now->head - tkns[t_i - 1].tail == 1)
			{
				t_i++;
			}
			else
				break ;
		}
		else
			break ;
	}
	return (t_i);
}
// single doubleがあった後にnormalが来ても大丈夫なように修正する

static size_t	count_words(const t_tkn *tkns, const size_t t_len)
{
	size_t	t_i;
	size_t	w_len;

	w_len = 0;
	t_i = 0;
	while (t_i < t_len)
	{
		if (type_is_redirect(tkns[t_i].type))
		{
			t_i++;
			t_i += count_word(&tkns[t_i], t_len);
		}
		else
		{
			t_i += count_word(&tkns[t_i], t_len);
			w_len++;
		}
	}
	return (w_len);
}

static int	store_words(char **words, const char *src, const t_tkn *tkns,
	const size_t t_len)
{
	size_t	t_i;
	size_t	tmp_len;
	size_t	w_i;

	w_i = 0;
	t_i = 0;
	while (t_i < t_len)
	{
		if (type_is_redirect(tkns[t_i].type))
		{
			t_i++;
			t_i += count_word(&tkns[t_i], t_len);
		}
		else
		{
			tmp_len = count_word(&tkns[t_i], t_len);
			words[w_i] = create_word(src, &tkns[t_i], tmp_len);
			if (!words[w_i])
				return (delete_words(words), 0);
			t_i += tmp_len;
			w_i++;
		}
	}
	return (words[w_i] = NULL, 1);
}

char	**create_words(const char *src, const t_tkn *tkns, const size_t t_len)
{
	char	**words;
	size_t	w_len;

	w_len = count_words(tkns, t_len);
	words = malloc(sizeof(char *) * (w_len + 1));
	if (!words)
		return (NULL);
	if (!store_words(words, src, tkns, t_len))
		return (NULL);
	return (words);
}

void	delete_words(char **words)
{
	size_t	i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
}
