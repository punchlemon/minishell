/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:19:15 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/29 20:48:56 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_exe(char **s_path_env, t_cmd *cmds)
{
	size_t	i;

	i = 0;
	free_two_dimensional_array(s_path_env);
	while (cmds[i].type != TAIL)
	{
		delete_cmd_exe(&cmds[i]);
		i++;
	}
	free(cmds);
}
