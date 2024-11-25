/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:39:39 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/25 19:16:44 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_H
# define SIG_H

# include "libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

extern volatile sig_atomic_t	g_signal;

void	idle_handler(int signum);
void	exec_handler(int signum);
void	set_exec_handler(bool wait_child);
void	set_idle_handler(void);
void	set_exec_child_handler(void);

#endif
