/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:18:27 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 15:02:42 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

typedef struct s_cmd
{
	int		in;
	int		out;
	char	**argv;
}	t_cmd;

// functions
// create_cmd.c
t_cmd	*create_cmd(char *src);

// delete_cmd.c
void	*delete_cmd(t_cmd *cmd);

#endif
