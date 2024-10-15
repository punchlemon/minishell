/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:44:52 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 14:11:30 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define CMD 0
# define AND 1
# define OR 2

#include "lexer.h"

// structures
typedef struct s_cmd
{
	int		in;
	int		out;
	char	**argv;
}	t_cmd;

typedef struct s_pipe
{
	t_cmd			*cmd;
	struct s_pipe	*next;
}	t_pipe;

typedef struct s_and_or
{
	int				op;
	t_pipe			*pipe;
}	t_and_or;

// functions
void		*delete_and_or(t_and_or *and_or);

#endif
