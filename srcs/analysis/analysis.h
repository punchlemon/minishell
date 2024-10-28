/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:02:10 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/28 23:59:08 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYSIS_H
# define ANALYSIS_H

# include "t_minishell.h"
# include "t_analysis.h"
# include "type.h"

void	print_conds(t_cond *conds);
void	print_tkns(t_tkn *tkns);
t_tkn	*lexer(const char *src, size_t *tkns_len);
t_cond	*parser(const char *src, const t_tkn *tkns, const size_t t_len);

#endif
