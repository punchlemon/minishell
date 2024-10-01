/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:18:07 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/30 23:54:50 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"

t_cmd_node	*analysis(char *src)
{
	t_str		*str;
	t_cmd_node	*cmd_n;

	if (!src)
		return (NULL);
	str = create_str(src);
	if (!str)
		return (NULL);
	if (!trim_space_str(&str))
		return (delete_str(str));
	cmd_n = and_or(str);
	delete_str(str);
	if (!cmd_n)
		return (NULL);
	return (cmd_n);
}
