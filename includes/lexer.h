/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:35:47 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/13 23:38:30 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# define END 0
# define SPACE 1
# define NORMAL 2
# define SINGLE 3 // '
# define DOUBLE 4 // "
# define AND_IF 5 // &&
# define OR_IF 6 // ||
# define PIPE 7 // |
# define LPAREN 8 // (
# define RPAREN 9 // )
# define LESS 10 // <
# define GREAT 11 // >
# define DLESS 12 // <<
# define DGREAT 13 // >>

# include "analysis.h"
# include <stdlib.h>

// functions
int		ft_istoken(const char c);
size_t	count_lex(const char *src);
void	store_lex(const char *str, t_lex_data *lex_data);
int		check_lex(t_lex_data *lex_data);

#endif
