/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:47:53 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/29 17:49:24 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "count_tkns_for.h"
# include "t_analysis.h"
# include "type.h"
# include "ft_printf.h"

int	check_word(const t_tkn *tkns, const size_t t_end);
int	check_cmd(const t_tkn *tkns, const size_t t_end);
int	check_conds(const t_tkn *tkns, const size_t t_end);

#endif
