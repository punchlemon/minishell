/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_extend.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:55:33 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/10 15:45:00 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_EXTEND_H
# define LIBFT_EXTEND_H

// functions
void	free_pp(void **pp);
int		ft_isspace(const char c);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split_func(const char *src, int (*f)(const char c));

#endif
