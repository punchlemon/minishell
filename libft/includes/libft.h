/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:17:04 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/24 14:25:50 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf.h"
# include "ft_printf_stderr.h"
# include <unistd.h>

// functions
// is
int		ft_isalpha(int c);
int		ft_isdigit(int c);

// mem
void	ft_bzero(void *dst, size_t n);
void	*ft_calloc(size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);

// put
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);

// str
char	**ft_split(const char *src, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);

#endif
