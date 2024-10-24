/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tkns.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:11:28 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/22 23:43:12 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_TKNS_H
# define COUNT_TKNS_H

#include "libft_extend.h"
# include <stdlib.h>

// functions
int	count_word(const char *src, size_t *i, size_t *len);
int	count_tkn(const char *src, size_t *i, size_t *len);

#endif
