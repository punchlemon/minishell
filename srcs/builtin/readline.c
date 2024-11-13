#include "list.h"
#include "cd.h"
#include "pwd.h"
#include "echo.h"
#include "env.h"
#include "exit.h"
#include "unset.h"
#include "export.h"

void	free_two_dimensional_array(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	excute_command(t_env **env, char *cmd, char **args)
{
	if (strcmp(cmd, "cd") == 0)
	{
		// write(1, "excute cd command\n", 19);
		builtin_cd(env, args);
		// print_list(env);
	}
	else if (strcmp(cmd, "pwd") == 0)
	{
		// write(1, "excute cd command\n", 19);
		builtin_pwd();
		// print_list(env);
	}
	else if (strcmp(cmd, "echo") == 0)
	{
		builtin_echo(args);
	}
	if (strcmp(cmd, "env") == 0)
	{
		builtin_env(env, args);
	}
	else if (strcmp(cmd, "exit") == 0)
	{
		builtin_exit(*env, args);
	}
	else if (strcmp(cmd, "export") == 0)
	{
		builtin_export(env, args);
	}
	else if (strcmp(cmd, "unset") == 0)
	{
		builtin_unset(env, args);
	}
}

// int	main(int argc, char **argv, char **environ)
// {
// 	t_env	*env;
// 	char	*line;
// 	char	**splited_line;
// 	char	*cmd;
// 	char	**args;
// 
// 	env = make_env_list(environ);
// 	while (1)
// 	{
// 		line = readline("minishell$ ");
// 		if (line == NULL)
// 			break ;
// 		if (*line)
// 			add_history(line);
// 		if (line == NULL || line[0] == '\0')
// 			continue ;
// 		splited_line = ft_split(line, ' ');
// 		cmd = splited_line[0];
// 		args = &splited_line[1];
// 		excute_command(&env, cmd, args);
// 		free_two_dimensional_array(splited_line);
// 
// 		free(line);
// 	}
// 	free_list(env);
// 	exit(0);
// }

// exit status
