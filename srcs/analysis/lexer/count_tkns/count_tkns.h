/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tkns.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:11:28 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/30 22:07:42 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_TKNS_H
# define COUNT_TKNS_H

# include "libft_extend.h"
# include <stdlib.h>

// functions
int	count_word_len(const char *src, size_t *i, size_t *len);
int	count_tkn(const char *src, size_t *i, size_t *len);

#endif
