/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:31:11 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 12:32:47 by retanaka         ###   ########.fr       */
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
	struct s_and_or	*next;
}	t_and_or;

// functions
// cmd
// create_and_or.c
t_and_or	*create_and_or_elm(t_str *str, int op);
t_and_or	*create_and_or(t_str_arr *str_arr);

// create_cmd.c
t_cmd		*create_cmd(t_str *str);

// create_pipe.c
t_pipe		*create_pipe(t_str *str);

// delete_and_or.c
void		*delete_and_or(t_and_or *and_or);

// delete_cmd.c
void	*delete_cmd(t_cmd *cmd);

// delete_pipe.c
void		*delete_pipe(t_pipe *pipe);

// print_and_or.c
void		print_and_or(t_and_or *and_or);

// analysis
// analysis.c
int			analysis(char *src, t_and_or **and_or_ref);

// and_or.c
t_and_or	*and_or(t_str **str_ref);

// split_str_and_or.c
int			move_quote(char *src, size_t *l);
int			move_paren(char *src, size_t *l);
int			check_and_or(t_str_arr *str_arr, char *src, size_t *i, size_t *l);
int			move_word(t_str_arr *str_arr, char *src, size_t *i, size_t *l);

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		**ft_split(char const *s, char c);

// void		exe(char **srcs, char **environ);
void		exe(char **srcs, char **environ, int *status);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);

#endif
