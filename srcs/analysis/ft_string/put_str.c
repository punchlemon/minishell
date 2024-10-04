/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:34:18 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/04 17:50:20 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	put_str_no_nl(t_str *str)
{
	put("[len:");
	put_num((unsigned int)str->len);
	put("\"");
	if (!str->data)
		write(1, "(null)", 6);
	else
		write(1, str->data, str->len);
	put("\"]");
}

void	put_str(t_str *str)
{
	put_str_no_nl(str);
	put("\n");
}

int	put_str_len(t_str *str, int *len)
{
	int	tmp;

	tmp = write(1, str->data, str->len);
	*len += tmp;
	return (tmp);
}
