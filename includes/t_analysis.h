/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_analysis.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:50:11 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/21 21:48:52 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ANALYSIS_H
# define T_ANALYSIS_H

# include <stdlib.h>

typedef struct s_token
{
	int		type;
	size_t	head;
	size_t	tail;
}	t_token;

#endif
