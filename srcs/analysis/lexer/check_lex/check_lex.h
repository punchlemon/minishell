/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:47:53 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/14 18:05:01 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_LEX_H
# define CHECK_LEX_H

# include "t_lex_data.h"

// functions
int	check_lex_and_or(const t_lex_data *lex_data, const size_t len);
int	check_lex_cmd(const t_lex_data *lex_data, size_t *i, const size_t len);
int	check_lex_io_redirect(const t_lex_data *lex_data, size_t *i,
		const size_t len);
int	check_lex_pipe(const t_lex_data *lex_data, size_t *i, const size_t len);
int	check_lex_subshell(const t_lex_data *lex_data, size_t *i, const size_t len);
int	check_lex_word(const t_lex_data *lex_data, size_t *i, const size_t len);

#endif
