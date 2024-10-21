/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokens.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:47:53 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 23:36:40 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_TOKENS_H
# define CHECK_TOKENS_H

# include "t_analysis.h"
# include "type.h"

int	check_tokens(const t_token *tokens);
int	check_cmd(const t_token *tokens, size_t *i);
int	check_word(const t_token *tokens, size_t *i);

#endif
