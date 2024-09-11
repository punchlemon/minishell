/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:08 by retanaka          #+#    #+#             */
/*   Updated: 2024/09/11 15:10:33by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(char *src)
{
	size_t	i;
	if (!src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	return (i);
}

void	delete_pp(char **src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		free(src[i]);
		i++;
	}
	free(src);
}

int	main(void)
{
	char	*buf;
	char	**split;
	size_t	i;
	char	c;

	buf = malloc(sizeof(char) * 42);
	if (!buf)
		return (1);
	read(0, buf, 42);
	split = ft_split(buf, ' ');
	if (!split)
		return (1);
	i = 0;
	while (split[i])
	{
		c = i + '0';
		write(1, &c, 1);
		write(1, ": ", 2);
		write(1, split[i], ft_strlen(split[i]));
		write(1, "\n", 1);
		i++;
	}
	delete_pp(split);
	return (0);
}
