/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:34:18 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/30 09:13:44 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	put_str(t_str *str, int *len)
{
	int	tmp;

	tmp = write(1, str->data, str->len);
	*len += tmp;
	return (tmp);
}
