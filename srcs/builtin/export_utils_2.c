/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:22:57 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/25 16:52:31 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include <ctype.h>

int	is_alpha_under(char c)
{
	if (ft_isalpha(c) || c == '_')
		return (1);
	return (0);
}

int	is_alpha_num_under(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c) || c == '_')
		return (1);
	return (0);
}

int	is_valid_key(char *key)
{
	if (!is_alpha_under(*key))
		return (0);
	key++;
	while (*key)
	{
		if (!is_alpha_num_under(*key))
			return (0);
		key++;
	}
	return (1);
}

void	malloc_error_exit(void)
{
	write(2, "Error: malloc\n", 14);
	exit(1);
}
