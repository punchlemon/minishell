/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:26:01 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/30 14:28:19 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"

int	builtin_env(t_env **env, char **args)
{
	t_env	*top;

	top = *env;
	if (args[0] != NULL)
	{
		ft_printf_stderr("env: ‘%s’: No such file or directory\n", args[0]);
		return (127);
	}
	while (top)
	{
		if (top->value)
			ft_printf("%s=%s\n", top->key, top->value);
		top = top->next;
	}
	return (0);
}
