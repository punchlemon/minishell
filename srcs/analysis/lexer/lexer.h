/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:35:47 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/05 07:57:23 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "t_analysis.h"
# include "type.h"
# include "libft_extend.h"
# include "ft_printf.h"
# include <stdlib.h>

// functions
int		ft_isspace(const char c);
int		ft_istoken(const char c);
int		ft_isquote(const char c);
int		ft_isnormal_word(const char c);
size_t	count_tkns(const char *src);
void	store_tkns(const char *str, t_tkn *tkns);

#endif
