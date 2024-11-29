/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:17:03 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/29 15:48:36 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "sig.h"
#include "ft_printf.h"
#include "ft_printf_stderr.h"
#include "libft.h"
#include "builtin.h"

void	delete_cmd_exe(t_cmd *cmd)
{
	size_t	i;

	i = 0;
	while (cmd->words[i])
		free(cmd->words[i++]);
	i = 0;
	while (cmd->reds[i].type != TAIL)
		free(cmd->reds[i++].target);
	free(cmd->words);
	free(cmd->reds);
}

void	count_cmd(size_t *words_len, size_t *reds_len, t_tkn *tkns);
int		store_cmd(t_cmd *cmd, t_tkn *tkns, t_env *env, char *st);

t_cmd	*expand_cmd(t_cmd *cmd, t_tkn *tkns, t_env *env, int status)
{
	size_t	words_len;
	size_t	reds_len;
	char	*st;

	st = ft_itoa(status);
	if (!st)
		return (NULL);
	count_cmd(&words_len, &reds_len, tkns);
	cmd->words = ft_xcalloc(sizeof(char *) * (words_len + 1));
	if (!cmd->words)
		return (free(st), NULL);
	cmd->reds = ft_xcalloc(sizeof(t_red) * (reds_len + 1));
	if (!cmd->reds)
		return (free(st), free(cmd->words), NULL);
	if (!store_cmd(cmd, tkns, env, st))
		return (free(st), NULL);
	return (free(st), cmd);
}

void	expand_cmds(t_cmd *cmds, t_cmd_a *cmd_as, t_env *env, int status)
{
	size_t	i;

	i = 0;
	while (cmds[i].type != TAIL)
	{
		expand_cmd(&cmds[i], cmd_as[i].tkns, env, status);
		i++;
	}
}
