/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:43:51 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/17 16:09:29 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cond	*parser(const char *src, const t_tokens *tokens)
{
	size_t		i;

	i = 0;
	return (create_conds(src, tokens, &i));
}
