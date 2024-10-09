/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:18:07 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/06 19:28:17 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"

int	analysis(char *src, t_and_or **and_or_ref)
{
	t_str		*str;

	if (!src)
		return (put(ANALYSIS_ERROR), 0);
	if (!src[0])
		return (1);
	str = create_str(src);
	if (!str)
		return (put(ANALYSIS_ERROR), 0);
	if (!trim_space_str(&str))
		return (put(ANALYSIS_ERROR), 0);
	if (is_equal_str(str, "exit"))
		return (delete_str(str), 2);
	*and_or_ref = and_or(&str);
	delete_str(str);
	if (!*and_or_ref)
		return (put(ANALYSIS_ERROR), 0);
	return (3);
}
