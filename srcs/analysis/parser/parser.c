/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:43:51 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/14 13:32:06 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "t_lex_data.h"
#include "and_or.h"
#include <stdlib.h>

t_and_or	*parser(char *src, t_lex_data *lex_data)
{
	if (src && lex_data)
		return (NULL);
	return (NULL);
}
