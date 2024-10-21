/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:05:36 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/17 17:09:50 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_lex.h"

int	check_lex(const t_tokens *tokens)
{
	return (check_and_or(tokens));
}
