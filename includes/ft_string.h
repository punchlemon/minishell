/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:49:10 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 13:58:04 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# include <unistd.h>

// structs
typedef struct s_str
{
	size_t	len;
	char	*data;
}	t_str;

typedef struct s_str_list
{
	t_str				*str;
	struct s_str_list	*next;
	struct s_str_list	*prev;
}	t_str_list;

typedef struct s_str_arr
{
	size_t		len;
	size_t		total;
	t_str_list	*list;
}	t_str_arr;

// ft_string functions
// append_str_arr.c
t_str_arr	*append_str_arr_one_str_no_total(t_str_arr *str_s, t_str *str);
t_str_arr	*append_str_arr_one_str(t_str_arr *str_s, t_str *str);
t_str_arr	*append_str_arr_one_src_len(t_str_arr *str_s, char *src
	, size_t len);
t_str_arr	*append_str_arr(t_str_arr *dst_s, t_str_arr *src_s);

// convert_str_to_char.c
char		*convert_str_to_char_p(t_str *str);
void		*free_char_pp(char **p_arr);
char		**convert_str_arr_to_char_pp(t_str_arr *str_s);

// create_str_arr.c
t_str_list	*create_str_list(t_str *str);
t_str_arr	*create_str_arr(t_str *str);

// create_str.c
t_str		*create_str(char *src);
t_str		*create_str_len(char *src, size_t len);

// delete_str_arr.c
void		*delete_str_list(t_str_list	*list);
void		*delete_str_arr(t_str_arr *strs);

// delete_str.c
void		*delete_str(t_str *str);

// get_str_arr.c
t_str_list	*get_str_list_from_str_arr(t_str_arr *str_s, size_t n);

// is_equal_str.c
int			is_equal_str(t_str *str, char *src);

// put_num.c
int			put_num(int num);
int			put_size_t(size_t num);

// put_str.c
void		put_str_no_nl(t_str *str);
void		put_str(t_str *str);
int			put_str_len(t_str *str, int *len);

// put_str_arr.c
void		put_str_arr(t_str_arr *str_s);
int			put_str_arr_len(t_str_arr *str_s, int *len);

// remove_str_arr.c
t_str_arr	*remove_str_arr_n(t_str_arr *str_s, size_t n);

// split_str_arr.c
t_str_arr	*split_str_arr_end_n(t_str_arr *str_s, size_t n);
t_str_arr	*split_str_arr_space(t_str_arr *str_s);

// split_str_and_or.c
t_str_arr	*split_str_ref_and_or(t_str **str_ref);

// split_str.c
t_str_arr	*split_str_space(t_str *str);

// trim_edge_str.c
void		trim_right_str_n(t_str *str, size_t n);
t_str		*trim_left_edge_str(t_str **str_ref);
void		trim_right_edge_str(t_str *str);
t_str		*trim_edge_str(t_str **str_ref);

// trim_space_str.c
t_str		*trim_left_space_str(t_str **str_ref);
size_t		trim_right_space_str(t_str *str);
t_str_arr	*trim_right_space_str_arr(t_str_arr *str_s);
t_str		*trim_space_str(t_str **str_ref);

// utils.c
int			ft_isspace(char c);
int			put(char *src);
int			put_len(char *src, size_t len);

#endif
