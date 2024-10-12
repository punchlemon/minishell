/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:26:13 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/12 12:51:06 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "libft_extend.h"
#include "minishell.h"

t_cmd	*create_cmd(const char *src)
{
	t_cmd		*cmd;
	char		**splitted_src;

	splitted_src = ft_split_func(src, ft_isspace);
	if (!splitted_src)
		return (NULL);
	cmd = ft_calloc(sizeof(t_cmd));
	cmd->argv = splitted_src;
	cmd->in = 0;
	cmd->out = 0;///// io_redirectによってfdが入れられる
	return (cmd);
}
