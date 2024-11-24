/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:22:34 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/24 16:22:35 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include "ft_printf_stderr.h"

int	builtin_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		if (errno == ENOENT || errno == ENOTDIR || errno == EACCES)
		{
			ft_printf_stderr("pwd: cannot get current working directory\n");
			return (1);
		}
		ft_printf_stderr("Error: getcwd\n");
		return (1);
	}
	ft_printf("%s\n", cwd);
	free(cwd);
	return (0);
}
