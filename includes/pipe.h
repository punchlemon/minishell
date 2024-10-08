/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:13:11 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 15:27:44 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "cmd.h"

// structures
typedef struct s_pipe
{
	t_cmd			*cmd;
	struct s_pipe	*next;
}	t_pipe;

// functions
// create_pipe.c
t_pipe		*create_pipe(char *src);

// delete_pipe.c
void		*delete_pipe(t_pipe *pipe);

#endif
