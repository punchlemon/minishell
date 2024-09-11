/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:49:10 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/11 19:01:18 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# include <unistd.h>

typedef struct s_string
{
	size_t	len;
	size_t	cap;
	char	*p;
}	t_string;

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(char *src);

#endif
