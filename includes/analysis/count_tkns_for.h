/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tkns_for.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:26:39 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/30 12:45:57 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_TKNS_FOR_H
# define COUNT_TKNS_FOR_H

# include "t_analysis.h"

size_t	count_tkns_for_word(const t_tkn *tkns, const size_t t_end);
size_t	count_tkns_for_cond(const t_tkn *tkns, const size_t t_end);
size_t	count_tkns_for_cmd(const t_tkn *tkns, const size_t t_end);
size_t	match_paren(const t_tkn *tkns, const size_t t_end);

#endif
