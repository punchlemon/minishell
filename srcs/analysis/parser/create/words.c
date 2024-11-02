/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:16:17 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/02 23:16:32 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

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
			t_i += count_tkns_for_word(&tkns[t_i], t_len);
		}
		else
		{
			t_i += count_tkns_for_word(&tkns[t_i], t_len);
			w_len++;
		}
	}
	return (w_len);
}

static int	store_words(char **words, const t_tkn *tkns, const size_t t_len)
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
			t_i += count_tkns_for_word(&tkns[t_i], t_len);
		}
		else
		{
			tmp_len = count_tkns_for_word(&tkns[t_i], t_len);
			words[w_i] = create_word(&tkns[t_i], tmp_len);
			if (!words[w_i])
				return (delete_words(words), 0);
			t_i += tmp_len;
			w_i++;
		}
	}
	return (words[w_i] = NULL, 1);
}

char	**create_words(const t_tkn *tkns, const size_t t_len)
{
	char	**words;
	size_t	w_len;

	w_len = count_words(tkns, t_len);
	words = malloc(sizeof(char *) * (w_len + 1));
	if (!words)
		return (NULL);
	if (!store_words(words, tkns, t_len))
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
