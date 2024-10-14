/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lex_and_or.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:42:52 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/14 17:35:21 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lex_data.h"
#include "check_lex.h"

int	check_lex_and_or(const t_lex_data *lex_data, const size_t len)
{
	size_t	i;

	i = 0;
	if (!check_lex_pipe(lex_data, &i, len))
		return (0);
	while (i < len)
	{
		if (lex_data[i].token == AND_IF || lex_data[i].token == OR_IF)
		{
			if (++i >= len)
				return (0);
		}
		else
			return (0);
		if (!check_lex_pipe(lex_data, &i, len))
			return (0);
	}
	return (1);
}
// subshellでも呼ばれるため長さを予め指定する必要がある
// 終端チェックは呼び出し元が行う
