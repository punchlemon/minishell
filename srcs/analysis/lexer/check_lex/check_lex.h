/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:47:53 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 23:37:08 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_LEX_H
# define CHECK_LEX_H

# include "lexer.h"

// functions
int	check_and_or(const t_tokens *tokens);
int	check_cmd(const t_tokens *tokens, size_t *i);
int	check_pipe(const t_tokens *tokens, size_t *i);
int	check_word(const t_tokens *tokens, size_t *i);
int	type_is_word(int type);
int	type_is_subshell(int type);
int	type_is_io_redirect(int type);
int	type_is_normal_cmd(int type);
int	type_is_cmd(int type);

#endif
