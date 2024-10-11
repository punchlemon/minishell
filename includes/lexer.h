/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:35:47 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/11 21:07:47 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>

// functions
// check_lex.c
int	check_lex(int *lex_data);

// count_lex.c
size_t	count_lex(const char *src);

// lexer.c
int		ft_istoken(const char c);
int		*lexer(const char *src);

// store_lex.c
void	store_lex(int *lex_data, const char *src);

#endif
