/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/11 13:49:34 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int	main(void)
{
	char	**ls_op;

	ls_op = malloc(sizeof(char *) * 4);
	if (!ls_op)
		return (1);

	ls_op[0] = "ls";
	ls_op[1] = "-llllll";
	ls_op[2] = "-a";
	ls_op[3] = NULL;
	if (!access("/usr/bin/ls", F_OK) && !access("/usr/bin/ls", X_OK))
		execv("/usr/bin/ls", ls_op);
	free(ls_op);
	return (0);
}
