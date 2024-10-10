/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 01:56:33 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/10 17:13:42 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "and_or.h"
#include "libft_extend.h"
static size_t	count_and_or(char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

static void	store_range_and_or(size_t *range, char src)
{
}

static size_t	lexer_and_or(size_t **range, char *src)
{
	size_t		len;

	len = count_and_or(src);
	if (!len)
		return (0);
	*range = ft_calloc(sizeof(size_t) * 3 * len + 1);
	if (!*range)
		return (0);
	store_range_and_or(*range, src);
	return (len);
}

static void	store_and_or(t_and_or *and_or, size_t *range, char src)
{
}

t_and_or	*create_and_or(char *src)
{
	char		**pp;
	t_and_or	*and_or;
	size_t		*range;
	size_t		len;

	len = lexer_and_or(src, &range);
	if (!range)
		return (NULL);
	and_or = ft_calloc(sizeof(t_and_or) * len + 1);
	if (!and_or)
		return (NULL);
	store_and_or(and_or, range, src);
	free(range);
	return (and_or);
}
