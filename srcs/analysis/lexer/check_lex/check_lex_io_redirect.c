/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lex_io_redirect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:45:23 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 13:58:17 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "check_lex.h"

int	check_lex_io_redirect(const t_lex_data *lex_data, size_t *i,
		const size_t len)
{
	if (++(*i) >= len)
		return (0);
	return (check_lex_word(lex_data, i, len));
}
