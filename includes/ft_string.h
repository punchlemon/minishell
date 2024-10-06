/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:49:10 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/06 18:39:52 by retanaka         ###   ########.fr       */
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

typedef struct s_str_slice
{
	size_t		len;
	size_t		total_str_len;
	t_str_list	*list;
}	t_str_slice;

// ft_string functions
// append_str_slice.c
t_str_slice	*append_str_slice_one_str_no_total(t_str_slice *str_s, t_str *str);
t_str_slice	*append_str_slice_one_str(t_str_slice *str_s, t_str *str);
t_str_slice	*append_str_slice_one_src_len(t_str_slice *str_s, char *src
	, size_t len);
t_str_slice	*append_str_slice(t_str_slice *dst_s, t_str_slice *src_s);

// create_str_slice.c
t_str_list	*create_str_list(t_str *str);
t_str_slice	*create_str_slice(t_str *str);

// create_str.c
t_str		*create_str(char *src);
t_str		*create_str_len(char *src, size_t len);

// delete_str_slice.c
void		*delete_str_list(t_str_list	*list);
void		*delete_str_slice(t_str_slice *strs);

// delete_str.c
void		*delete_str(t_str *str);

// get_str_slice.c
t_str_list	*get_str_list_from_str_slice(t_str_slice *str_s, size_t n);

// is_equal_str.c
int			is_equal_str(t_str *s1, t_str *s2);
int			is_equal_str_src(t_str *str, char *src);

// put_num.c
int			put_num(int num);
int			put_unum(unsigned int num);

// put_str.c
void		put_str_no_nl(t_str *str);
void		put_str(t_str *str);
int			put_str_len(t_str *str, int *len);

// put_str_slice.c
void		put_str_slice(t_str_slice *str_s);
int			put_str_slice_len(t_str_slice *str_s, int *len);

// remove_str_slice.c
t_str_slice	*remove_str_slice_n(t_str_slice *str_s, size_t n);

// split_str_slice.c
t_str_slice	*split_str_slice_end_n(t_str_slice *str_s, size_t n);
t_str_slice	*split_str_slice_space(t_str_slice *str_s);

// split_str_and_or.c
t_str_slice	*split_str_ref_and_or(t_str **str_ref);

// split_str.c
t_str_slice	*split_str_space(t_str *str);

// str_to_char.c
char		*str_to_char_array(t_str *str);
void		*free_char_pntr_array(char **p_arr, size_t n);
char		**str_slice_to_char_pntr_array(t_str_slice *str_s);

// trim_edge_str.c
void		trim_right_str_n(t_str *str, size_t n);
t_str		*trim_left_edge_str(t_str **str_ref);
void		trim_right_edge_str(t_str *str);
t_str		*trim_edge_str(t_str **str_ref);

// trim_space_str.c
t_str		*trim_left_space_str(t_str **str_ref);
size_t		trim_right_space_str(t_str *str);
t_str_slice	*trim_right_space_str_slice(t_str_slice *str_s);
t_str		*trim_space_str(t_str **str_ref);

// utils.c
int			ft_isspace(char c);
size_t		ft_strlen(char *src);
int			put(char *src);
int			put_len(char *src, size_t len);

#endif
