/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:53:59 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/26 00:09:55 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "create_delete.h"

size_t	count_word(const t_tkn *head, const t_tkn *tail)
{
	size_t		w_len;
	const t_tkn	*now;
	size_t		t_i;

	w_len = head->tail - head->head;
	t_i = 1;
	while (head + t_i == tail)
	{
		now = &head[t_i];
		if (now->type == SINGLE || now->type == DOUBLE)
		{
			if (now->head - head[t_i - 1].tail == 1)
			{
				w_len += now->tail - now->head;
				t_i++;
			}
			else
				break ;
		}
		else
			break ;
	}
	return (w_len);
}

static void	store_word(char *word, const char *src, const t_tkn *head,
	const t_tkn *tail)
{
	const t_tkn	*now;
	size_t		t_i;

	ft_memmove(word, src + head->head, head->tail - head->head);
	t_i = 1;
	while (head + t_i == tail)
	{
		now = &head[t_i];
		if (now->type == SINGLE || now->type == DOUBLE)
		{
			if (now->head - head[t_i - 1].tail == 1)
			{
				ft_memmove(word + t_i, src + now->head, now->tail - now->head);
				t_i++;
			}
			else
				return ;
		}
		else
			return ;
	}
	return ;
}

char	*create_word(const char *src, const t_tkn *head, const t_tkn *tail)
{
	char	*word;
	size_t	w_len;

	w_len = count_word(head, tail);
	word = malloc(w_len + 1);
	if (!word)
		return (NULL);
	store_word(word, src, head, tail);
	return (word);
}
