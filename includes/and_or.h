/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:09:05 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/12 12:49:59 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AND_OR_H
# define AND_OR_H

# define CMD 0
# define AND 1
# define OR 2

# include "pipe.h"

// structures
typedef struct s_and_or
{
	int				op;
	t_pipe			*pipe;
}	t_and_or;

// functions
// delete_and_or.c
void		*delete_and_or(t_and_or *and_or);

// print_and_or.c
void		print_and_or(t_and_or *and_or);

#endif
