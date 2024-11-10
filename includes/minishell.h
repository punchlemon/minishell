/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:31:11 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/09 15:25:28 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "t_minishell.h"
# include "execution.h"
# include "type.h"
# include "ft_printf.h"

t_cond	*analysis(char *src);
void	delete_conds(t_cond *conds);

#endif
