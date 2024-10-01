/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:31:11 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/01 16:18:35 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define CMD 0
# define AND 1
# define OR 2
# define ANALYSIS_ERROR "minishell: syntax error\n"

# include "ft_string.h"
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_pipe_cmd
{
	t_str_slice	*str_s;
}	t_pipe_cmd;

typedef struct s_cmd_node
{
	int					op;
	t_pipe_cmd			*p_cmd;
	struct s_cmd_node	*next;
}	t_cmd_node;

// functions
// cmd
// create_cmd_node.c
t_cmd_node	*create_cmd_node_elm(t_str *str, int op);
t_cmd_node	*create_cmd_node(t_str_slice *str_s);

// create_pipe_cmd.c
t_pipe_cmd	*create_pipe_cmd(t_str_slice *str_s);

// delete_cmd_node.c
void		*delete_cmd_node(t_cmd_node *cmd_n);

// delete_pipe_cmd.c
void		*delete_pipe_cmd(t_pipe_cmd *p_cmd);

// analysis
// analysis.c
t_cmd_node	*analysis(char *src);

// and_or.c
t_cmd_node	*and_or(t_str *str);

// is_valid_str_and_or.c
int			is_valid_str_and_or(t_str *str);

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		**ft_split(char const *s, char c);

void		exe(char **srcs, char **environ);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);

#endif
