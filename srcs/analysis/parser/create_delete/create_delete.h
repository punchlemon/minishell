/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_delete.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:15:40 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 23:42:54 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_DELETE_H
# define CREATE_DELETE_H

# include "t_analysis.h"
# include "t_minishell.h"
# include "type.h"

char		*create_word(const char *src, const t_token *tokens, size_t *i);
char		**create_words(const char *src, const t_token *tokens, size_t i);
t_redirect	*create_redirects(const char *src, const t_token *tokens, size_t i);
t_cmd_unit	*create_pipeline(const char *src, const t_token *tokens, size_t *i);
t_cond		*create_conds(const char *src, const t_token *tokens, size_t *i);
void		delete_words(char **words);
void		delete_redirects(t_redirect *redirects);
void		delete_pipeline(t_cmd_unit *pipeline);
void		delete_conds(t_cond *conds);

#endif
