/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_put_letter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:51:12 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/19 15:59:07 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_stderr.h"

ssize_t	printf_c(char c, int **crr_len)
{
	(**crr_len)++;
	return (write(2, &c, 1));
}

ssize_t	printf_s(char *str, int **crr_len)
{
	size_t	len_str;

	if (!str)
	{
		**crr_len += 6;
		return (write(2, "(null)", 6));
	}
	len_str = ft_strlen(str);
	**crr_len += (int)len_str;
	return (write(2, str, len_str));
}

ssize_t	printf_percent(int **crr_len)
{
	(**crr_len)++;
	return (write(2, "%", 1));
}
