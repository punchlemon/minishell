/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_lex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:21:22 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 13:48:14 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORE_LEX_H
# define STORE_LEX_H

# include "lexer.h"

// functions
void	store_token(t_lex_data *lex_data, const char *src, size_t *i,
			size_t *lex_data_i);
void	store_word(t_lex_data *lex_data, const char *src, size_t *i,
			size_t *lex_data_i);

#endif
