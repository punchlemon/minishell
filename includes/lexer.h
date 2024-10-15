/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:35:47 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 13:56:03 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>

// structions
typedef struct s_lex_data
{
	int		token;
	size_t	head;
	size_t	tail;
}	t_lex_data;

// functions
size_t	count_lex(const char *src);
void	store_lex(const char *str, t_lex_data *lex_data);
int		check_lex(const t_lex_data *lex_data, const size_t lex_data_len);

#endif
