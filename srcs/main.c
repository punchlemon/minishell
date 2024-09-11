/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/11 17:50:29 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **environ)
{
	char	*buf;
	char	**split;

	(void)argc;
	(void)argv;
	buf = malloc(sizeof(char) * 42);
	if (!buf)
		return (1);
	read(0, buf, 42);
	split = ft_split(buf, ' ');
	if (!split)
		return (1);
	exe(split, environ);
	return (0);
}
