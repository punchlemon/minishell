/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:02:10 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/23 01:06:55 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYSIS_H
# define ANALYSIS_H

# include "t_minishell.h"
# include "t_analysis.h"
# include "type.h"

void	print_conds(t_cond *conds);
void	print_tkns(t_tkn *tkns);
t_tkn	*lexer(const char *src);
t_cond	*parser(const char *src, const t_tkn *tkns);

#endif
