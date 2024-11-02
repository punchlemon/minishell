/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istoken.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:38:41 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/02 22:48:30 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (!ft_istoken(c) && !ft_isquote(c));
}
