/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:44:52 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/17 12:54:43 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "t_analysis.h"
# include "t_minishell.h"

t_cond	*create_exec_plan(const char *src, const t_tokens *tokens, size_t *i);

#endif
