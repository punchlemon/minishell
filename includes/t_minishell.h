/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:55:48 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 01:53:57 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MINISHELL_H
# define T_MINISHELL_H

# include <stdlib.h>

typedef struct s_redirect
{
	int		type;
	char	*target;
}	t_redirect;

typedef struct s_cmd_unit
{
	int			type;
	char		**words;
	t_redirect	*redirects;
	t_cond		*conds;
}	t_cmd_unit;

typedef struct s_cond
{
	int			type;
	t_cmd_unit	*pipeline;
}	t_cond;

#endif
