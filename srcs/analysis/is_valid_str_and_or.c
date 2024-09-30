/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_str_and_or.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:51:11 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/30 17:57:43 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	count_bracket(int *bracket_num_ref, char c)
{
	if (c == '(')
		*bracket_num_ref += 1;
	else if (c == ')')
		*bracket_num_ref -= 1;
}

int	manage_and_or_flag(char *and_or_flag_ref, char c)
{
	if (*and_or_flag_ref == 1)
	{
		if (c != '&' && c != '|' && c != '\0')
			*and_or_flag_ref = 0;
		else if (is_space(c))
			return (1);
		else
			return (0);
	}
	else if (c == *and_or_flag_ref)
		*and_or_flag_ref = 1;
	else
		return (0);
}

int	update_and_or_flag(char *and_or_flag_ref, int bracket_num, char c, size_t i)
{
	if (!bracket_num)
	{
		if (*and_or_flag_ref)
		{
			if (!manage_and_or_flag(and_or_flag_ref, c))
				return (0);
		}
		else if (c == '&' || c == '|')
		{
			if (i == 0)
				return (0);
			else
				*and_or_flag_ref = c;
		}
	}
	return (1);
}

void	update_quote_flag(char *quote_flag_ref, int bracket_num, char c)
{
	if (!bracket_num)
	{
		if (!*quote_flag_ref)
		{
			if (c == '\'' || c == '"')
				*quote_flag_ref = c;
		}
		else if (*quote_flag_ref == c)
			*quote_flag_ref = 0;
	}
}

int	is_valid_str_and_or(t_str *str)
{
	char	quote_flag;
	char	and_or_flag;
	int		bracket_num;
	char	c;
	size_t	i;

	quote_flag = 0;
	and_or_flag = 0;
	bracket_num = 0;
	i = 0;
	while (i < str->len)
	{
		c = str->data[i];
		if (!quote_flag)
		{
			if (!update_and_or_flag(&and_or_flag, bracket_num, c, i))
				return (0);
			count_bracket(&bracket_num, c);
		}
		update_quote_flag(&quote_flag, bracket_num, c);
		i++;
	}
	return (!and_or_flag && !quote_flag && !bracket_num);
}
