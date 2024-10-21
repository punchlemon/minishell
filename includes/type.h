/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:04:19 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 21:47:27 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

// token type
# define TAIL 0
# define HEAD 1
# define AND_IF 3 // &&
# define OR_IF 4 // ||
# define NORMAL 5
# define SUBSHELL 6
# define SINGLE 8 // '
# define DOUBLE 9 // "
# define PIPE 10 // |
# define LPAREN 11 // (
# define RPAREN 12 // )
# define LESS 13 // <
# define GREAT 14 // >
# define DLESS 15 // <<
# define DGREAT 16 // >>
# define DOLLAR 17 // $
# define ASTERISK 18 // *

int	type_is_word(int type);
int	type_is_subshell(int type);
int	type_is_redirect(int type);
int	type_is_normal(int type);
int	type_is_cmd(int type);

#endif
