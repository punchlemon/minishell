/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:02:10 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/14 12:31:53 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYSIS_H
# define ANALYSIS_H

# include "and_or.h"
# include "t_lex_data.h"
# include <stdlib.h>

// structions

// functions
t_lex_data	*lexer(const char *src);
t_and_or	*parser(char *src, t_lex_data *lex_data);

#endif
