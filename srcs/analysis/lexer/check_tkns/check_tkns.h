/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tkns.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:47:53 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/23 01:07:30 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_TKNS_H
# define CHECK_TKNS_H

# include "t_analysis.h"
# include "type.h"

int	check_tkns(const t_tkn *tkns);
int	check_cmd(const t_tkn *tkns, size_t *i);
int	check_word(const t_tkn *tkns, size_t *i);

#endif
