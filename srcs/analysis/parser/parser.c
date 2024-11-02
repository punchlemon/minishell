/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:43:51 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/02 23:17:42 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cond	*parser(const t_tkn *tkns, const size_t t_end)
{
	return (create_conds(tkns, t_end));
}
