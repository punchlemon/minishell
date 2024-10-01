/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:32:12 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/01 16:21:07 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <unistd.h>

// ft_memory functions
// ft_calloc.c
void	*ft_calloc(size_t n);

// ft_memcpy.c
void	ft_memcpy(char *dst, char *src, size_t n);

// ft_memzero.c
void	ft_memzero(char *dst, size_t n);

// is_equal_mem.c
int		is_equal_mem(char *s1, char *s2, size_t n);

#endif
