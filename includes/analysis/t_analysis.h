/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_analysis.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:50:11 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/22 23:32:28 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ANALYSIS_H
# define T_ANALYSIS_H

# include <stdlib.h>

typedef struct s_tkn
{
	int		type;
	size_t	head;
	size_t	tail;
}	t_tkn;

#endif
