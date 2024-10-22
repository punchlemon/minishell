/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_delete.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:15:40 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/23 00:58:59:10 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_DELETE_H
# define CREATE_DELETE_H

# include "t_analysis.h"
# include "t_minishell.h"
# include "type.h"

char	*create_word(const char *src, const t_tkn *tkns, size_t *i);
char	**create_words(const char *src, const t_tkn *tkns, size_t i);
t_red	*create_reds(const char *src, const t_tkn *tkns, size_t i);
t_cmd	*create_cmds(const char *src, const t_tkn *head, const t_tkn *tail);
t_cond	*create_conds(const char *src, const t_tkn *head, const t_tkn *tail);
void	delete_words(char **words);
void	delete_reds(t_red *reds);
void	delete_cmds(t_cmd *cmds);
void	delete_conds(t_cond *conds);
size_t	match_paren(const t_tkn *tkns);

#endif
