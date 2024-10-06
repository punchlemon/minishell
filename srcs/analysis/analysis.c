/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:18:07 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/06 17:14:24 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"

int	analysis(char *src, t_cmd_node **cmd_n_ref)
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
	if (is_equal_str_src(str, "exit"))
		return (delete_str(str), 2);
	*cmd_n_ref = and_or(&str);
	delete_str(str);
	if (!*cmd_n_ref)
		return (put(ANALYSIS_ERROR), 0);
	return (3);
}
