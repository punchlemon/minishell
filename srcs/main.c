/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/12 18:23:36 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **environ)
{
	char	*buf;
	char	**pp;

	(void)argc;
	(void)argv;
	(void)environ;
	buf = malloc(sizeof(char) * 42);
	if (!buf)
		return (1);
	read(0, buf, 42);
	pp = and_or(buf);
	if (!pp)
		return (1);
	exe(pp, environ);
	return (0);
}
