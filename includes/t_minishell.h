/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:55:48 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/22 23:22:13 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MINISHELL_H
# define T_MINISHELL_H

# include <stdlib.h>

typedef struct s_red
{
	int		type;
	char	*target;
}	t_red;

typedef struct s_cmd
{
	int				type;
	char			**words;
	t_red			*reds;
	struct s_cond	*conds;
}	t_cmd;

typedef struct s_cond
{
	int		type;
	t_cmd	*cmds;
}	t_cond;

#endif
