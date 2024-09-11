/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:49:10 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/11 19:23:30 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# include <unistd.h>

// structs
typedef struct s_string
{
	size_t	len;
	size_t	cap;
	char	*p;
}	t_string;

typedef struct s_string_slice
{
	size_t		len;
	size_t		cap;
	t_string	**p;
}	t_string_slice;

// functions
size_t		ft_strlen(char *src);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		*delete_string(t_string *str);
t_string	*create_string(char *src);
t_string	*create_string_len(size_t len);
void		copy_bytes(void *dst, void *src, size_t bytes);

#endif
