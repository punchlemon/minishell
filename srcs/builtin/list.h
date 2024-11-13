#ifndef LIST_H
# define LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

typedef struct s_env
{
	struct s_env	*next;
	char			*key;
	char			*value;
}	t_env;

t_env	*search_end(t_env *top);
void	add_node_to_list(t_env **top, t_env *node);
t_env	*make_new_node(char *line);
void	free_list(t_env *top);
void	print_list(t_env *top);
void	set_env(t_env *env, char *key, char *value);
t_env	*make_env_list(char **environ);
void	excute_command(t_env **env, char *cmd, char **args);

#endif