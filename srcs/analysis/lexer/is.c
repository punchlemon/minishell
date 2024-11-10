/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:50:51 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/05 07:57:05 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(const char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_istoken(const char c)
{
	return (c == '&' || c == '|'
		|| c == '(' || c == ')'
		|| c == '<' || c == '>');
}

int	ft_isquote(const char c)
{
	return (c == '"' || c == '\'');
}

int	ft_isnormal_word(const char c)
{
	return (!ft_istoken(c) && !ft_isquote(c) && !ft_isspace(c) && c);
}
