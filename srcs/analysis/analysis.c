/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:18:07 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 20:46:43 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"

int	analysis(char *src, t_and_or **and_or_ref)
{
	// if (!trim_space_str(&str))
	// 	return (put(ANALYSIS_ERROR), 0);
	// if (!*(str->data))
	// 	return (delete_str(str), 1);
	*and_or_ref = and_or(src);
	// delete_str(str);
	if (!*and_or_ref)
		return (put(ANALYSIS_ERROR), 0);
	return (3);
}
