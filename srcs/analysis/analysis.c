/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:47:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/12 13:03:55 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include <stdlib.h>

t_and_or	*analysis(char *src)
{
	int			*lex_data;
	t_and_or	*and_or;

	lex_data = lexer(src);
	if (!lex_data)
		return (NULL);
	and_or = parser(src, lex_data);
	free(lex_data);
	return (and_or);
}
