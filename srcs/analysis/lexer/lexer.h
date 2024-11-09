/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:35:47 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/06 15:56:18 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "t_minishell.h"
# include "libft_extend.h"
# include "ft_printf.h"

// functions
int		ft_isspace(const char c);
int		ft_istoken(const char c);
int		ft_isquote(const char c);
int		ft_isnormal(const char c);
size_t	count_t_len(const char *src);
void	store_tkns(const char *str, t_tkn *tkns);

#endif
