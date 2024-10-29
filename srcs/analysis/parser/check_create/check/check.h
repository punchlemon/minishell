/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:47:53 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/29 11:04:14 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "t_analysis.h"
# include "type.h"
# include "ft_printf.h"

int	check_conds(const t_tkn *tkns, const size_t t_len);
int	check_cmd(const t_tkn *tkns, size_t *i);
int	check_word(const t_tkn *tkns, size_t *i);

#endif
