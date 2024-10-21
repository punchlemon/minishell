/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_lex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:21:22 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/17 16:10:45 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORE_LEX_H
# define STORE_LEX_H

# include "t_analysis.h"
# include <stdlib.h>

// functions
void	store_token(t_tokens *tokens, const char *src, size_t *i, size_t *t_i);
void	store_word(t_tokens *tokens, const char *src, size_t *i, size_t *t_i);

#endif
