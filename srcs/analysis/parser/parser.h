/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:44:52 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 00:51:54 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "t_analysis.h"
# include "t_minishell.h"

t_cond	*create_conds(const char *src, const t_tokens *tokens, size_t *i);

#endif
