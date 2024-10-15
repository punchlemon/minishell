/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:47:53 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 16:32:34 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_LEX_H
# define CHECK_LEX_H

# include "lexer.h"

// functions
int	check_lex_and_or(const t_lex_data *lex_data, const size_t len);
int	check_lex_cmd(const t_lex_data *lex_data, size_t *i, const size_t len);
int	check_lex_pipe(const t_lex_data *lex_data, size_t *i, const size_t len);
int	check_lex_word(const t_lex_data *lex_data, size_t *i, const size_t len);
int	token_is_word(int token);
int	token_is_subshell(int token);
int	token_is_io_redirect(int token);
int	token_is_normal_cmd(int token);
int	token_is_cmd(int token);

#endif
