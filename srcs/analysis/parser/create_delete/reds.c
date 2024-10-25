/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:53:34 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/26 00:41:23 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_delete.h"

static size_t	count_reds(const t_tkn *head, const t_tkn *tail)
{
	size_t	t_i;
	size_t	r_len;

	r_len = 0;
	t_i = 0;
	while (1)
	{
		if (type_is_redirect(head[t_i].type))
		{
			t_i++;
			t_i += count_word(&head[t_i], tail);
			r_len++;
		}
		else
			t_i += count_word(&head[t_i], tail);
		if (&head[t_i] == tail)
			return (r_len);
	}
}

static int	store_reds(t_red *reds, const char *src, const t_tkn *head,
	const t_tkn *tail)
{
	size_t	t_i;
	size_t	t_len;
	size_t	r_i;

	r_i = 0;
	t_i = 0;
	while (1)
	{
		if (type_is_redirect(head[t_i].type))
		{
			reds[r_i].type = head[t_i].type;
			t_i++;
			t_len = count_word(&head[t_i], tail);
			reds[r_i].target = create_word(src, &head[t_i], &head[t_i] + t_len);
			if (!reds[r_i].target)
				return (reds[r_i].type = TAIL, delete_reds(reds), 0);
			t_i += t_len;
			r_i++;
		}
		else
			t_i += count_word(&head[t_i], tail);
		if (&head[t_i] == tail)
			return (reds[r_i].type = TAIL, 1);
	}
}
// シンプルなwordの時の処理をどのようにするかについて考える

t_red	*create_reds(const char *src, const t_tkn *head, const t_tkn *tail)
{
	t_red	*reds;
	size_t	r_len;

	r_len = count_reds(head, tail);
	reds = malloc(sizeof(t_red) * (r_len + 1));
	if (!reds)
		return (NULL);
	if (!store_reds(reds, src, head, tail))
		return (NULL);
	return (reds);
}

void	delete_reds(t_red *reds)
{
	size_t	i;

	i = 0;
	while (reds[i].type != TAIL)
		free(reds[i++].target);
	free(reds);
}
