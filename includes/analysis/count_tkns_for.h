/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tkns_for.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:26:39 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/29 16:42:33 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_TKNS_FOR_H
# define COUNT_TKNS_FOR_H

# include "t_analysis.h"

size_t	count_tkns_for_cond(const t_tkn *tkns, const size_t t_len);
size_t	count_tkns_for_cmd(const t_tkn *tkns, const size_t t_len);

#endif
