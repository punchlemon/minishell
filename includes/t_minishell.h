/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:55:48 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/17 12:58:00 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MINISHELL_H
# define T_MINISHELL_H

// cond type
# define TAIL 0
# define HEAD 1
# define AND 2
# define OR 3

// cmd_unit type
# define TAIL 0
# define SUBSHELL 1
# define NORMAL_CMD 2

# include <stdlib.h>

typedef struct s_redirect
{
	int		type;
	char	*target;
}	t_redirect;

typedef struct s_normal_cmd
{
	char		**words;
	t_redirect	*redirects;
}	t_normal_cmd;

typedef struct s_subshell
{
	t_cond		*conds;
	t_redirect	*redirects;
}	t_subshell;

typedef struct s_cmd_unit
{
	int				type;
	t_subshell		*subshell;
	t_normal_cmd	*normal_cmd;
}	t_cmd_unit;

typedef struct s_cond
{
	int			type;
	t_cmd_unit	*pipeline;
}	t_cond;

#endif
