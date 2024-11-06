/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:55:48 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/06 12:44:11 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MINISHELL_H
# define T_MINISHELL_H

# include <stdlib.h>

typedef struct s_red
{
	int		type;
	char	*target;
	int		file_fd;
	int		std_target_fd;
}	t_red;

typedef struct s_cmd
{
	int				type;
	char			**words;
	t_red			*reds;
	int				pipe_in[2];
	int				pipe_out[2];
	struct s_cond	*conds;
}	t_cmd;

typedef struct s_cond
{
	int		type;
	t_cmd	*cmds;
}	t_cond;

#endif
