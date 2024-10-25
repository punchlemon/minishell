/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:16:17 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/26 00:56:41 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_delete.h"
#include "ft_printf.h"

static size_t	count_words(const t_tkn *head, const t_tkn *tail)
{
	size_t	t_i;
	size_t	w_len;

	w_len = 0;
	t_i = 0;
	while (1)
	{
		if (type_is_redirect(head[t_i].type))
		{
			t_i++;
			t_i += count_word(&head[t_i], tail);
		}
		else
		{
			t_i += count_word(&head[t_i], tail);
			w_len++;
		}
		if (&head[t_i] == tail)
			return (w_len);
	}
}

static int	store_words(char **words, const char *src, const t_tkn *head,
	const t_tkn *tail)
{
	size_t	t_i;
	size_t	t_len;
	size_t	w_i;

	w_i = 0;
	t_i = 0;
	while (1)
	{
		if (type_is_redirect(head[t_i].type))
		{
			t_i++;
			t_i += count_word(&head[t_i], tail);
		}
		else
		{
			t_len = count_word(&head[t_i], tail);
			words[w_i] = create_word(src, &head[t_i], &head[t_i + t_len]);
			if (!words[w_i])
				return (delete_words(words), 0);
			t_i += t_len;
			w_i++;
		}
		if (&head[t_i] == tail)
			return (words[w_i] = NULL, 1);
	}
}

char	**create_words(const char *src, const t_tkn *head, const t_tkn *tail)
{
	char	**words;
	size_t	w_len;

	w_len = count_words(head, tail);
	words = malloc(sizeof(char *) * (w_len + 1));
	if (!words)
		return (NULL);
	if (!store_words(words, src, head, tail))
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
