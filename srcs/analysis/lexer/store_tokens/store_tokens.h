/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tokens.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:21:22 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 23:14:20 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORE_TOKENS_H
# define STORE_TOKENS_H

# include "t_analysis.h"
# include <stdlib.h>

// functions
void	store_token(t_token *tokens, const char *src, size_t *i, size_t *t_i);
void	store_word(t_token *tokens, const char *src, size_t *i, size_t *t_i);

#endif
