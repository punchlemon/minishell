/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:13:57 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/25 23:30:24 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "ft_printf.h"

void	print_tkns(t_tkn *tkns)
{
	size_t		i;

	i = 0;
	while (tkns[i].type != TAIL)
	{
		ft_printf("i:%u type:%d, head:%u, tail:%u\n",
			(unsigned int)i,
			tkns[i].type,
			(unsigned int)tkns[i].head,
			(unsigned int)tkns[i].tail);
		i++;
	}
}

static void	print_words(char **words)
{
	size_t	i;

	ft_printf("      [words]");
	if (!words)
		return ((void)ft_printf(" NULL\n"));
	i = 0;
	while (words[i])
	{
		if (i)
			ft_printf(", ");
		ft_printf(" \"%s\"", words[i]);
		i++;
	}
	ft_printf("\n");
}

static void	print_redirects(t_red *redirects)
{
	(void)redirects;
}

static void	print_pipeline(t_cmd *pipeline)
{
	size_t	i;

	ft_printf("  [pipeline]\n");
	if (!pipeline)
		return ((void)ft_printf("    NULL\n"));
	i = 0;
	while (pipeline[i].type != TAIL)
	{
		ft_printf("    type:");
		if (pipeline[i].type == NORMAL)
			ft_printf("    NORMAL\n");
		else if (pipeline[i].type == SUBSHELL)
			ft_printf("    SUBSHELL\n");
		else
			return ((void)ft_printf("    ELSE!!!!\n"));
		print_conds(pipeline[i].conds);
		print_words(pipeline[i].words);
		print_redirects(pipeline[i].reds);
		i++;
	}
}

void	print_conds(t_cond *conds)
{
	size_t	i;

	ft_printf("[conds]\n");
	if (!conds)
		return ((void)ft_printf("NULL\n"));
	i = 0;
	while (conds[i].type != TAIL)
	{
		ft_printf("  type:");
		if (conds[i].type == AND_IF)
			ft_printf("  AND\n");
		else if (conds[i].type == OR_IF)
			ft_printf("  OR\n");
		else if (conds[i].type == HEAD)
			ft_printf("  HEAD\n");
		else
			return ((void)ft_printf("  ELSE!!!!!\n"));
		print_pipeline(conds[i].cmds);
		i++;
	}
}
