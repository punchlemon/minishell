/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lex_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:30:42 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/14 16:09:46 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LEX_DATA_H
# define T_LEX_DATA_H

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

# include <stdlib.h>

typedef struct s_lex_data
{
	int		token;
	size_t	head;
	size_t	tail;
}	t_lex_data;

#endif