/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lex_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:30:42 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/14 12:31:36 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LEX_DATA_H
# define T_LEX_DATA_H

# include <stdlib.h>

typedef struct s_lex_data
{
	int		token;
	size_t	head;
	size_t	tail;
}	t_lex_data;

#endif
