/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:30:20 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/01 16:23:47 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include <stdlib.h>

void	*delete_str(t_str *str)
{
	ft_memzero(str->data, str->len);
	free(str->data);
	str->data = NULL;
	str->len = 0;
	str->cap = 0;
	free(str);
	return (NULL);
}
