/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:55:48 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/18 14:28:38 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MINISHELL_H
# define T_MINISHELL_H

# define TAIL 0
# define HEAD 1
# define AND_IF 2
# define OR_IF 3
# define PIPE 4
# define NORMAL 5
# define SINGLE 6
# define DOUBLE 7
# define LESS 8
# define GREAT 9
# define DLESS 10
# define DGREAT 11
# define DOLLAR 12

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
	int		type;
	char	**words;
	t_red	*reds;
	pid_t	pid;
	int		pipe_in[2];
	int		pipe_out[2];
}	t_cmd;

typedef struct s_tkn
{
	int			type;
	const char	*head;
	const char	*tail;
}	t_tkn;

typedef struct s_cmd_a
{
	t_tkn	*tkns;
}	t_cmd_a;

typedef struct s_cond
{
	int		type;
	t_cmd_a	*cmds;
}	t_cond;

int	type_is_word(int type);
int	type_is_red(int type);
int	type_is_cmd(int type);
int	type_is_cmds(int type);
int	type_is_and_or(int type);

#endif
