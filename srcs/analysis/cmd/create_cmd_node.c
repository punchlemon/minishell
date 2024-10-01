/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:13:14 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/01 00:12:02 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include "minishell.h"

t_cmd_node	*create_cmd_node_elm(t_str_slice *str_s)
{
	t_cmd_node	*cmd_node;

	if (!str_s)
		return (NULL);
	cmd_node = ft_calloc(sizeof(t_cmd_node));
	if (!cmd_node)
		return (NULL);
	cmd_node->op = CMD;
	cmd_node->p_cmd = create_pipe_cmd(str_s);
	if (!cmd_node->p_cmd)
		return (free(cmd_node), NULL);
	return (cmd_node);
}

t_cmd_node	*create_cmd_node(t_str_slice *str_s)
{
	t_cmd_node	*cmd_n;
	t_cmd_node	*tmp_n;
	t_str		*str;
	size_t		i;

	str = str_s->list->str;
	i = 0;
	while (i < str_s->len)
	{
		if (!compare_str_src(str, "&&"));
		else if (!compare_str_src(str, "||"));
	}
	return (cmd_n);
}
/// この関数でsplit_str_slice_spaceも行っていい感じにする
/// けど、今後の開発でpipe_cmdに対する一般的な処理が固まってきたらそれを適用する
