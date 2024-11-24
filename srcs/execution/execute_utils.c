/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:36:29 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/24 19:03:34 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "sig.h"
#include "ft_printf.h"
#include "ft_printf_stderr.h"
#include "libft.h"
#include "builtin.h"

size_t	count_env_len(t_env *env)
{
	size_t	len;

	len = 0;
	while (env != NULL)
	{
		env = env->next;
		len++;
	}
	return (len);
}

char	**env_to_environ(t_env *env)
{
	char	**strs;
	char	*tmp;
	size_t	i;

	strs = (char **)ft_xcalloc(sizeof(char *) * (count_env_len(env) + 1));
	if (strs == NULL)
		return (NULL);
	i = 0;
	while (env != NULL && env->value != NULL)
	{
		strs[i] = ft_strjoin(env->key, "=");
		if (strs[i] == NULL)
			return (free_two_dimensional_array(strs), NULL);
		tmp = strs[i];
		strs[i] = ft_strjoin(strs[i], env->value);
		if (strs[i] == NULL)
			return (free_two_dimensional_array(strs), NULL);
		free(tmp);
		env = env->next;
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
