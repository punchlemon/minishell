/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:27:38 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/25 16:50:23 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include <ctype.h>
#include "ft_printf_stderr.h"

int	is_num(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	str++;
	while (ft_isdigit(*str))
		str++;
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}
