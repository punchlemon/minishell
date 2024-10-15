/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:02:10 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 13:55:44 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYSIS_H
# define ANALYSIS_H

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

# include "parser.h"
# include "lexer.h"
# include <stdlib.h>

// functions
t_lex_data	*lexer(const char *src);
t_and_or	*parser(char *src, t_lex_data *lex_data);

#endif
