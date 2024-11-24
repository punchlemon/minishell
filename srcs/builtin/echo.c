/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:27:26 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/24 15:27:27 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"

int	check_option(char *arg)
{
	int	i;

	i = 0;
	if (arg == NULL)
		return (0);
	if (arg[i] != '-')
		return (0);
	i++;
	if (arg[i] != 'n')
		return (0);
	i++;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	builtin_echo(char **args)
{
	int		option;
	int		first;
	size_t	i;

	option = 0;
	i = 0;
	option = check_option(args[i]);
	if (option)
		i++;
	while (check_option(args[i]) && args[i])
		i++;
	first = 1;
	while (args[i] != NULL)
	{
		if (first)
			first = 0;
		else
			ft_printf(" ");
		ft_printf("%s", args[i]);
		i++;
	}
	if (!option)
		ft_printf("\n");
	return (0);
}

// int	main(void)
// {
// 	char	**args;

// 	args = malloc(sizeof(char *) * 4);
// 	args[0] = "-nnnnnn";
// 	args[1] = "-na";
// 	args[2] = "tutsumi";
// 	args[3] = NULL;
// 	builtin_echo(NULL, args);
// }
