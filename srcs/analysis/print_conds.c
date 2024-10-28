/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:13:57 by retanaka          #+#    #+#             */
/*   Updated: 2024/10/29 00:56:56 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "ft_printf.h"

static void	print_words(char **words, size_t level)
{
	size_t	i;

	print_indent("[words]\n", level);
	if (!words)
		return ((void)print_indent("NULL\n", level + 1));
	print_indent("", level + 1);
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

static void	print_redirects(t_red *reds, size_t level)
{
	size_t	i;

	print_indent("[reds]\n", level);
	if (!reds)
		return ((void)print_indent("NULL\n", level + 1));
	i = 0;
	while (reds[i].type != TAIL)
	{
		print_indent("type:", level + 1);
		if (reds[i].type == LESS)
			ft_printf(" less\n");
		else if (reds[i].type == GREAT)
			ft_printf(" great\n");
		else if (reds[i].type == DLESS)
			ft_printf(" dless\n");
		else if (reds[i].type == DGREAT)
			ft_printf(" dgreat\n");
		print_indent("target:", level + 1);
		ft_printf(" \"%s\"\n", reds[i].target);
		i++;
	}
}

static void	print_pipeline(t_cmd *pipeline, size_t level)
{
	size_t	i;

	print_indent("[cmds]\n", level);
	if (!pipeline)
		return ((void)print_indent("NULL\n", level + 1));
	i = 0;
	while (pipeline[i].type != TAIL)
	{
		print_indent("type:", level + 1);
		if (pipeline[i].type == NORMAL)
		{
			ft_printf(" normal\n");
			print_words(pipeline[i].words, level + 1);
		}
		else if (pipeline[i].type == SUBSHELL)
		{
			ft_printf(" subshell\n");
			print_conds(pipeline[i].conds, level + 1);
		}
		else
			return ((void)ft_printf(" else!!!!\n"));
		print_redirects(pipeline[i].reds, level + 1);
		i++;
	}
}

void	print_conds(t_cond *conds, size_t level)
{
	size_t	i;

	print_indent("[conds]\n", level);
	if (!conds)
		return ((void)print_indent("NULL\n", level + 1));
	i = 0;
	while (conds[i].type != TAIL)
	{
		print_indent("type:", level + 1);
		if (conds[i].type == AND_IF)
			ft_printf(" and\n");
		else if (conds[i].type == OR_IF)
			ft_printf(" or\n");
		else if (conds[i].type == HEAD)
			ft_printf(" head\n");
		else
			return ((void)ft_printf(" else!!!!!\n"));
		print_pipeline(conds[i].cmds, level + 1);
		i++;
	}
}
