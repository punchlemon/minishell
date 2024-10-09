/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:09:05 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 20:45:40 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AND_OR_H
# define AND_OR_H

# define CMD 0
# define AND 1
# define OR 2

# include "ft_string.h"
# include "pipe.h"

// structures
typedef struct s_and_or
{
	int				op;
	t_pipe			*pipe;
	struct s_and_or	*next;
}	t_and_or;

// functions
// create_and_or.c
t_and_or	*create_and_or_elm(t_str *str, int op);
t_and_or	*create_and_or(t_str_arr *str_arr);

// delete_and_or.c
void		*delete_and_or(t_and_or *and_or);

// print_and_or.c
void		print_and_or(t_and_or *and_or);

// and_or.c
t_and_or	*and_or(char *src);

// split_str_and_or.c
int			move_quote(char *src, size_t *l);
int			move_paren(char *src, size_t *l);
int			check_and_or(t_str_arr *str_arr, char *src, size_t *i, size_t *l);
int			move_word(t_str_arr *str_arr, char *src, size_t *i, size_t *l);

#endif
