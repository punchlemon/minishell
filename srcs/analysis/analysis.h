/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:02:10 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/24 15:13:59 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYSIS_H
# define ANALYSIS_H

# include "t_minishell.h"
# include "ft_printf.h"
# include "libft_extend.h"

void	print_word(const char *head, const char *tail);
void	print_tkns(t_tkn *tkns);
void	print_conds(t_cond *conds);
t_tkn	*lexer(const char *src);
int		checker(const t_tkn *tkns);
t_cond	*parser(const t_tkn *tkns);

#endif
