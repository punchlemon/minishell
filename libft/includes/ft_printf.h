/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:18:36 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/12 13:18:41 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char s);
int		ft_putstr(char *s);
int		ft_putchar_check(char s, int *count);
int		ft_putstr_check(char *s, int *count);
int		ft_putnum_check(char n, char format, int *count);
int		ft_putptr_check(unsigned long long p, int *count);
int		ft_putoct_check(unsigned int n, int *count);
int		ft_putdec_check(int n, char format, int *count);
int		ft_puthex_check(unsigned int n, char format, int *count);
void	get_digit(unsigned long long n, int *digit, int base);
char	get_place_num(unsigned long long n, int digit, int base);
void	remove_place_num(unsigned long long *n, int digit, int base);
int		ft_putnumber_check(unsigned long long n, char f, int *count, int base);
int		ft_printf(const char *str, ...);

#endif
