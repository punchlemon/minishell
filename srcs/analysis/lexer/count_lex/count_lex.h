/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:11:28 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/15 22:58:24 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_LEX_H
# define COUNT_LEX_H

# include <stdlib.h>

// functions
int	count_word(const char *src, size_t *i, size_t *len);
int	count_token(const char *src, size_t *i, size_t *len);

#endif
