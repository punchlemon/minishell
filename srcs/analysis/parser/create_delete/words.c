/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:16:17 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/25 20:27:24 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_delete.h"

static size_t	count_words(const t_tkn *head, const t_tkn *tail)
{
	(void)head;
	(void)tail;
	return (0);
}

char	*create_word(const char *src, const t_tkn *head, const t_tkn *tail)
{
	(void)src;
	(void)head;
	(void)tail;
	return (NULL);
}

char	**create_words(const char *src, const t_tkn *head, const t_tkn *tail)
{
	char	**words;
	size_t	words_count;
	size_t	words_i;

	return (NULL);
	words_count = count_words(head, tail);
	words = malloc(sizeof(char *) * (words_count + 1));
	if (!words)
		return (NULL);
	words_i = 0;
	while (words_i < words_count)
	{
		words[words_i] = create_word(src, head, tail);
		if (!words[words_i])
		{
			while (words_i--)
				free(words[words_i]);
			return (free(words), NULL);
		}
		words_i++;
	}
	return (words);
}

void	delete_words(char **words)
{
	size_t	i;

	if (!words)
		return ;
	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
}
