/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:13:57 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/09 14:03:29by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "ft_printf.h"

void	print_indent(char *src, size_t level)
{
	while (level--)
		ft_printf("  ");
	ft_printf(src);
}

static void	print_word(const char *head, const char *tail, size_t level)
{
	print_indent("", level);
	if (!head)
		return ((void)print_indent("NULL\n", level + 1));
	print_indent("", level + 1);
	write(1, head, tail - head);
	ft_printf("\n");
}

void	print_tkns(t_tkn *tkns, size_t level)
{
	size_t	i;

	print_indent("[tkns]\n", level);
	if (!tkns)
		return ((void)print_indent("NULL\n", level + 1));
	i = 0;
	while (tkns[i].type != TAIL)
	{
		print_indent("type:", level + 1);
		if (tkns[i].type == NORMAL)
			ft_printf(" normal\n");
		else if (tkns[i].type == SINGLE)
			ft_printf(" '\n");
		else if (tkns[i].type == DOUBLE)
			ft_printf(" \"\n");
		else if (tkns[i].type == LESS)
			ft_printf(" <\n");
		else if (tkns[i].type == GREAT)
			ft_printf(" >\n");
		else if (tkns[i].type == DLESS)
			ft_printf(" <<\n");
		else if (tkns[i].type == DGREAT)
			ft_printf(" >>\n");
		else if (tkns[i].type == AND_IF)
			ft_printf(" &&\n");
		else if (tkns[i].type == OR_IF)
			ft_printf(" ||\n");
		print_word(tkns[i].head, tkns[i].tail, level + 1);
		i++;
	}
}

void	print_cmds(t_tkn **cmds, size_t level)
{
	size_t	i;

	i = 0;
	while (cmds[i])
	{
		print_tkns(cmds[i], level + 1);
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
			ft_printf(" &&\n");
		else if (conds[i].type == OR_IF)
			ft_printf(" ||\n");
		else if (conds[i].type == HEAD)
			ft_printf(" head\n");
		else
			return ((void)ft_printf(" else!!!!!\n"));
		print_cmds(conds[i].cmds, level + 1);
		i++;
	}
}
