/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tkns.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:21:22 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/22 23:41:13 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORE_TKNS_H
# define STORE_TKNS_H

# include "t_analysis.h"
# include <stdlib.h>

// functions
void	store_tkn(t_tkn *tkns, const char *src, size_t *i, size_t *t_i);
void	store_word(t_tkn *tkns, const char *src, size_t *i, size_t *t_i);

#endif
