/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:59:38 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/25 16:58:17 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_count_words(size_t *word_count, const char *src,
	int (*f)(const char c))
{
	size_t	i;

	*word_count = 0;
	i = 0;
	while (src[i])
	{
		while (src[i] && f(src[i]))
			i++;
		if (src[i])
			(*word_count)++;
		while (src[i] && !f(src[i]))
			i++;
	}
}

static void	ft_count_word_lengths(size_t *word_lengths, const char *src,
	int (*f)(const char c))
{
	size_t	i;
	size_t	j;
	size_t	word_length;

	word_length = 0;
	j = 0;
	i = 0;
	while (src[i])
	{
		while (src[i] && f(src[i]))
			i++;
		while (src[i] && !f(src[i]))
		{
			word_length++;
			i++;
		}
		word_lengths[j] = word_length;
		j++;
	}
}

static char	**allocate_word_memory(size_t *word_lengths, char **pp
	, size_t word_count)
{
	size_t	i;

	pp[word_count] = NULL;
	i = 0;
	while (i < word_count)
	{
		pp[i] = malloc(sizeof(char) * (word_lengths[i] + 1));
		if (!pp[i])
		{
			while (i--)
			{
				free(pp[i]);
				pp[i] = NULL;
			}
			free(pp);
			pp = NULL;
			break ;
		}
		i++;
	}
	while (word_count--)
		word_lengths[word_count] = 0;
	return (free(word_lengths), pp);
}

static void	ft_store_words(char **pp, const char *src, int (*f)(const char c))
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	i = 0;
	while (src[i])
	{
		k = 0;
		while (src[i] && f(src[i]))
			i++;
		while (src[i] && !f(src[i]))
		{
			pp[j][k] = src[i];
			i++;
			k++;
		}
		j++;
	}
}

char	**ft_split_func(const char *src, int (*f)(const char c))
{
	char	**pp;
	size_t	word_count;
	size_t	*word_lengths;

	ft_count_words(&word_count, src, f);
	word_lengths = malloc(sizeof(size_t) * (word_count));
	if (!word_lengths)
		return (NULL);
	ft_count_word_lengths(word_lengths, src, f);
	pp = malloc(sizeof(char *) * (word_count + 1));
	if (!pp)
		return (free(word_lengths), NULL);
	if (!allocate_word_memory(word_lengths, pp, word_count))
		return (NULL);
	ft_store_words(pp, src, f);
	return (pp);
}
