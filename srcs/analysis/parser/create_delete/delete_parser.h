/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:33:49 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/17 12:58:58 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DELETE_PARSER_H
# define DELETE_PARSER_H

# include "t_minishell.h"

void	delete_subshell(t_subshell *subshell);
void	delete_normal_cmd(t_normal_cmd *normal_cmd);
void	delete_cond(t_cond *cond);
void	delete_conds(t_cond *conds);

#endif
