/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:35:47 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/29 01:27:01 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "t_analysis.h"
# include "type.h"
# include <stdlib.h>

// functions
int		check_tkns(const t_tkn *tkns, const size_t t_len);
size_t	count_tkns(const char *src);
void	store_tkns(const char *str, t_tkn *tkns);

#endif
