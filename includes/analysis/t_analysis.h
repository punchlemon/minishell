/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_analysis.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:50:11 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/02 22:30:30 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ANALYSIS_H
# define T_ANALYSIS_H

# include <stdlib.h>

typedef struct s_tkn
{
	int			type;
	const char	*head;
	const char	*tail;
}	t_tkn;

#endif
