/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_indent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:45:28 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/29 00:45:46 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "ft_printf.h"

void	print_indent(char *src, size_t level)
{
	while (level--)
		ft_printf("  ");
	ft_printf(src);
}
