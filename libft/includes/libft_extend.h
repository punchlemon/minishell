/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_extend.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:55:33 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/05 07:57:18 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_EXTEND_H
# define LIBFT_EXTEND_H

// functions
void	free_pp(char **pp);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split_func(const char *src, int (*f)(const char c));

#endif
