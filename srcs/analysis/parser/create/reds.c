/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:53:34 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/02 23:16:46 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

static size_t	count_reds(const t_tkn *tkns, const size_t t_len)
{
	size_t	t_i;
	size_t	r_len;

	r_len = 0;
	t_i = 0;
	while (t_i < t_len)
	{
		if (type_is_redirect(tkns[t_i].type))
		{
			t_i++;
			t_i += count_tkns_for_word(&tkns[t_i], t_len);
			r_len++;
		}
		else
			t_i += count_tkns_for_word(&tkns[t_i], t_len);
	}
	return (r_len);
}

static int	store_reds(t_red *reds, const t_tkn *tkns, const size_t t_len)
{
	size_t	t_i;
	size_t	tmp_len;
	size_t	r_i;

	r_i = 0;
	t_i = 0;
	while (t_i < t_len)
	{
		if (type_is_redirect(tkns[t_i].type))
		{
			reds[r_i].type = tkns[t_i].type;
			t_i++;
			tmp_len = count_tkns_for_word(&tkns[t_i], t_len);
			reds[r_i].target = create_word(&tkns[t_i], tmp_len);
			if (!reds[r_i].target)
				return (reds[r_i].type = TAIL, delete_reds(reds), 0);
			t_i += tmp_len;
			r_i++;
		}
		else
			t_i += count_tkns_for_word(&tkns[t_i], t_len);
	}
	return (reds[r_i].type = TAIL, 1);
}

t_red	*create_reds(const t_tkn *tkns, const size_t t_len)
{
	t_red	*reds;
	size_t	r_len;

	r_len = count_reds(tkns, t_len);
	reds = malloc(sizeof(t_red) * (r_len + 1));
	if (!reds)
		return (NULL);
	if (!store_reds(reds, tkns, t_len))
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
