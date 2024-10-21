/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:47:53 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/17 16:10:24 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_LEX_H
# define CHECK_LEX_H

# include "t_analysis.h"
# include <stdlib.h>

int	check_and_or(const t_tokens *tokens);
int	check_cmd(const t_tokens *tokens, size_t *i);
int	check_pipe(const t_tokens *tokens, size_t *i);
int	check_word(const t_tokens *tokens, size_t *i);

#endif
