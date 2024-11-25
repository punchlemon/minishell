/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:31:26 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/25 15:38:20 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "sig.h"
#include "ft_printf.h"
#include "ft_printf_stderr.h"
#include "libft.h"
#include "builtin.h"

int	ft_is_charactor(char c)
{
	return (c == '_' || ft_isalpha(c) || ft_isdigit(c));
}

size_t	charactors_len(const char *src)
{
	size_t	len;

	len = 2;
	while (ft_is_charactor(src[len]))
		len++;
	return (len);
}

size_t	check_valiable(const char *src)
{
	if (src[0] != '$')
		return (0);
	if (src[1] == '?')
		return (2);
	if (src[1] == '_' || ft_isalpha(src[1]))
		return (charactors_len(src));
	return (0);
}

char	*get_value(const char *src, t_env *env, char *st)
{
	char	*key;
	size_t	len;
	char	*value;

	if (*src != '$')
		return (NULL);
	if (src[1] != '_' && !ft_isalpha(src[1]) && src[1] != '?')
		return (NULL);
	if (src[1] == '?')
		return (st);
	len = check_valiable(src) - 1;
	key = ft_xcalloc(sizeof(char) * (len + 1));
	key[len] = '\0';
	ft_memmove(key, &src[1], len);
	value = search_env_return_its_value(env, key);
	free(key);
	return (value);
}

int	is_env_variable(const char *head, const char *tail)
{
	size_t	len;
	size_t	i;

	len = tail - head;
	if (*head != '$' || len < 2)
		return (0);
	if (head[1] != '_' && !ft_isalpha(head[1]))
		return (0);
	i = 1;
	while (i < len)
	{
		if (!ft_is_charactor(head[i]))
			return (0);
		i++;
	}
	return (1);
}
