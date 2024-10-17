/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:15:40 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/17 13:40:50 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_PARSER_H
# define CREATE_PARSER_H

# include "t_analysis.h"
# include "t_minishell.h"

char			*create_word(const char *src, const t_tokens *tokens,
					size_t *i);
t_redirect		*create_redirect(const char *src, const t_tokens *tokens,
					size_t *i);
t_normal_cmd	*create_normal_cmd(const char *src, const t_tokens *tokens,
					size_t *i);
t_subshell		*create_subshell(const char *src, const t_tokens *tokens,
					size_t *i);
t_cmd_unit		*create_pipeline(const char *src, const t_tokens *tokens,
					size_t *i);
t_cond			*create_conds(const char *src, const t_tokens *tokens,
					size_t *i);

#endif
