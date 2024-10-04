/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:18:07 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/04 21:37:22 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"

void	*put_analysis_error(void)
{
	put(ANALYSIS_ERROR);
	return (NULL);
}

t_cmd_node	*analysis(char *src)
{
	t_str		*str;
	t_cmd_node	*cmd_n;

	if (!src)
		return (put_analysis_error());
	if (!src[0])
		return (NULL);
	str = create_str(src);
	if (!str)
		return (put_analysis_error());
	cmd_n = and_or(&str);
	delete_str(str);
	if (!cmd_n)
		return (put_analysis_error());
	return (cmd_n);
}
