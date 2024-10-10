/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:31:11 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/10 16:45:17 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SYNTAX_ERROR() write(1, "minishell: syntax error\n", 24)

# include "and_or.h"
# include "execution.h"

#endif
