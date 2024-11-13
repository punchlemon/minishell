#ifndef EXIT_H
# define EXIT_H

# include "list.h"

void	is_numeric(int argc, char **args);
void	is_not_numeric(int argc, char **args);
int		check_overflow(char *str);
int		is_num(char *str);
int		count_args(char **args);
int		builtin_exit(t_env *env, char **args);

#endif