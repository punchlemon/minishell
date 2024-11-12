/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:57:18 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/10 14:34:06 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*all_free(char **ans, char **buf, char **mem, char flag)
{
	if (flag == -1 || **ans == '\0')
	{
		free(*buf);
		buf = NULL;
		free(*ans);
		ans = NULL;
		if (*mem)
		{
			free(*mem);
			*mem = NULL;
		}
		return (NULL);
	}
	else
	{
		free(*buf);
		buf = NULL;
		if (*mem)
		{
			free(*mem);
			*mem = NULL;
		}
		return (*ans);
	}
}

int	put(char **ans, char *buf, char **mem)
{
	char	*temp;
	ssize_t	res;
	int		flag;

	if (buf == NULL)
		return (0);
	flag = 0;
	res = nobu_strchar(buf, '\n');
	if (res == 0)
		return (0);
	temp = nobu_strjoin(*ans, buf, res);
	if (temp == NULL)
		return (-1);
	free(*ans);
	*ans = temp;
	if (buf[res - 1] == '\n')
	{
		flag = 1;
		temp = ft_strdup(buf + res);
		if (temp == NULL)
			return (-1);
		free(*mem);
		*mem = temp;
	}
	return (flag);
}

int	nobu_set(char **ans, char **buf, int *flag)
{
	*flag = 0;
	*ans = (char *)malloc(sizeof(char) * 1);
	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*ans == NULL || *buf == NULL)
		return (1);
	*ans[0] = '\0';
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*ans;
	static char	*mem;
	int			flag;
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (nobu_set(&ans, &buf, &flag))
		return (all_free(&ans, &buf, &mem, -1));
	flag = put(&ans, mem, &mem);
	if (flag == -1)
		return (all_free(&ans, &buf, &mem, -1));
	while (flag == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (all_free(&ans, &buf, &mem, -1));
		buf[n] = '\0';
		flag = put(&ans, buf, &mem);
		if (flag == -1 || (n == 0 && *ans == '\0') || n == 0)
			return (all_free(&ans, &buf, &mem, flag));
	}
	free(buf);
	return (ans);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	fd;
// 	int	i;
// 	char	*res;

// 	i = 0;
// 	fd = open("get_next_line.c", O_RDONLY);
// 	// while (i++ < 3)
// 	// 	printf("main-res = %p\n", get_next_line(fd));
// 	while (1)
// 	{
// 		res = get_next_line(fd);
// 		if(res == NULL)
// 			break ;
// 		printf("%s", res);
// 		free(res);
// 	}
// 	close(fd);
// 	return (0);
// }

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }
