/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:35:47 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/12 14:41:29 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# define NORMAL 0
# define SINGLE 1 // ' 1 1 3
# define DOUBLE 2 // "
# define SPACE 3
# define AND_IF 4 // && 4
# define OR_IF 5 // || 5
# define PIPE 6 // |
# define LPAREN 7 // (
# define RPAREN 8 // )
# define LESS 9 // <
# define GREAT 10 // >
# define DLESS 11 // <<
# define DGREAT 12 // >>

# include <stdlib.h>

// functions
// check_lex.c
int	check_lex(size_t *lex_data);

// count_lex.c
size_t	count_lex(const char *src);

// lexer.c
int		ft_istoken(const char c);
size_t	*lexer(const char *src);

// store_lex.c
void	store_lex(size_t *lex_data, const char *src);

#endif
