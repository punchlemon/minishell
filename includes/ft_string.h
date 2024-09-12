/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:49:10 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/12 17:56:23 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# include <unistd.h>
# include <stdlib.h>

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
	t_string	*p;
}	t_string_slice;

// functions
int				compare_bytes(void *a, void *b, size_t bytes);
void			copy_bytes(void *dst, void *src, size_t bytes);
t_string_slice	*create_string_slice(t_string *str);
t_string_slice	*create_string_slice_len(size_t len);
void			*delete_string_slice(t_string_slice *str_slice);
void			put_string_slice(t_string_slice *str_slice, int *len);
void			*delete_string(t_string *str);
t_string		*create_string(char *src);
t_string		*create_string_len(size_t len);
void			put_string(t_string *str, int *len);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
void			mem_zero(void *dst, size_t bytes);
t_string_slice	*split_string(t_string *str);
char			*string_to_char(t_string *str);
char			**string_slice_to_char_array(t_string_slice *str_slice);
size_t			ft_strlen(char *src);
int				update_cap(size_t len, size_t *cap);

#endif
