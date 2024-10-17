/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:43:51 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/17 00:37:41 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_analysis.h"
#include "t_minishell.h"
#include "parser.h"

#include "ft_printf.h"

t_exec_plan	*parser(const char *src, const t_tokens *tokens)
{
	size_t		i;

	i = 0;
	return (create_exec_plan(src, tokens, &i));
}
