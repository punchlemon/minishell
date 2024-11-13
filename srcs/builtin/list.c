#include "list.h"
#include "cd.h"
#include "export.h"

t_env	*search_end(t_env *top)
{
	while (top->next != NULL)
		top = top->next;
	return (top);
}

void	add_node_to_list(t_env **top, t_env *node)
{
	t_env	*end;

	if (*top == NULL)
	{
		*top = node;
		node->next = NULL;
	}
	else
	{
		end = search_end(*top);
		end->next = node;
	}
}

t_env	*make_new_node(char *line)
{
	t_env	*node;
	char	*key;
	char	*value;

	node = calloc(1, sizeof(t_env));
	if (node == NULL)
		malloc_error_exit();
	if (strchr(line, '='))
	{
		key = strndup(line, ((size_t)(strchr(line, '=')) - (size_t)line));
		node->key = key;
		value = strdup(strchr(line, '=') + 1);
		if (value == NULL)
			malloc_error_exit();
		node->value = value;
	}
	else
	{
		key = strdup(line);
		node->key = key;
		node->value = NULL;
	}
	if (key == NULL)
		malloc_error_exit();
	return (node);
}

t_env	*make_env_list(char **environ)
{
	t_env	*top;
	t_env	*node;
	int		i;

	i = 0;
	top = NULL;
	while (environ[i])
	{
		node = make_new_node(environ[i]);
		add_node_to_list(&top, node);
		i++;
	}
	return (top);
}

// int	main(int argc, char **argv, char **environ)
// {
// 	t_env	*top;
// 	char	**args;

// 	args = malloc(sizeof(char *) * 2);
// 	args[0] = "../yes";
// 	args[1] = NULL;
// 	top = make_env_list(environ);
// 	builtin_cd(args, top);
// 	// print_list(top);
// 	free_list(top);
// 	return (0);
// }
