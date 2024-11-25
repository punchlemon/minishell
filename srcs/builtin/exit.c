/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:23:11 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/25 18:38:07 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include <ctype.h>
#include "ft_printf_stderr.h"

int	count_args(char **args)
{
	int	count;

	count = 0;
	if (args == NULL)
		return (count);
	while (args[count])
		count++;
	return (count);
}

int	check_overflow(char *str)
{
	long	num;
	long	prev;

	num = 0;
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		prev = num;
		num = num * 10 + (*str - '0');
		if (prev > num)
			return (1);
		str++;
	}
	return (0);
}

void	is_numeric(int argc, char **args, int status, int is_child)
{
	if (is_child == 0)
		ft_printf_stderr("exit\n");
	if (argc != 1)
	{
		ft_printf_stderr("minishell: exit: too many arguments\n");
		if (status)
			exit(status);
		else
			exit(1);
	}
	else
	{
		if (check_overflow(args[0]))
		{
			ft_printf_stderr("minishell: exit: %s: numeric argument required\n",
				args[0]);
			exit(2);
		}
		else
			exit(ft_atoi(args[0]) % 256);
	}
}

void	is_not_numeric(int argc, char **args, int is_child)
{
	(void)argc;
	if (is_child == 0)
		ft_printf_stderr("exit\n");
	ft_printf_stderr("minishell: exit: %s: numeric argument required\n",
		args[0]);
	exit(2);
}

int	builtin_exit(t_env *env, char **args, int status, int is_child)
{
	int	argc;

	argc = count_args(args);
	free_list(env);
	if (argc == 0)
	{
		if (is_child == 0)
			ft_printf_stderr("exit\n");
		exit(status);
	}
	else
	{
		if (is_num(args[0]))
			is_numeric(argc, args, status, is_child);
		else
			is_not_numeric(argc, args, is_child);
	}
	return (1);
}

// int	main(void)
// {
// 	char	*args[4];

// 	// args[0] = " 	+12 +12  ";
// 	// args[1] = "1";
// 	// args[2] = "c";
// 	args[0] = NULL;
// 	args[1] = NULL;
// 	args[2] = NULL;
// 	args[3] = NULL;
// 	builtin_exit(args);
// }
