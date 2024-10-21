/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:16:17 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 16:44:43 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_delete.h"

static size_t	count_words(const t_tokens *tokens, size_t i)
{
}

char	*create_word(const char *src, const t_tokens *tokens, size_t *i)
{
}

char	**create_words(const char *src, const t_tokens *tokens, size_t i)
{
	char	**words;
	size_t	words_count;
	size_t	words_i;

	words_count = count_words(tokens, i);
	words = malloc(sizeof(char *) * (words_count + 1));
	if (!words)
		return (NULL);
	words_i = 0;
	while (words_i < words_count)
	{
		words[words_i] = create_word(src, tokens, &i);
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
