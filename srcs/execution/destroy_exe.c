/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:19:15 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/29 16:19:33 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_exe(char **s_path_env, t_cmd *cmds)
{
	free_two_dimensional_array(s_path_env);
	delete_cmd_exe(cmds);
	free(cmds);
}
