/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:02:10 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/09 13:47:04 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYSIS_H
# define ANALYSIS_H

# include "t_minishell.h"
# include "ft_printf.h"

void	print_indent(char *src, size_t level);
void	print_tkns(t_tkn *tkns, size_t level);
void	print_conds(t_cond *conds, size_t level);
t_tkn	*lexer(const char *src);
int		checker(const t_tkn *tkns);
t_cond	*parser(const t_tkn *tkns);

#endif
