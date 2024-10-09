/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:20:17 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/09 14:24:41 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYSIS_H
# define ANALYSIS_H

# define ANALYSIS_ERROR "minishell: syntax error\n"

# include "and_or.h"

// functions
// analysis.c
int			analysis(char *src, t_and_or **and_or_ref);

#endif
