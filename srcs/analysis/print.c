/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:13:57 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/12 16:23:55 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "ft_printf.h"

void	print_word(const char *head, const char *tail)
{
	if (!head)
		return ((void)ft_printf("NULL"));
	write(1, head, tail - head);
}

void	print_tkns(t_tkn *tkns)
{
	size_t	i;

	ft_printf("[tkns]\n");
	if (!tkns)
		return ((void)ft_printf("NULL\n"));
	i = 0;
	ft_printf("====================\n");
	ft_printf("=type=\t| =content=\n");
	ft_printf("========|===========\n");
	while (tkns[i].type != TAIL)
	{
		if (type_is_cmd(tkns[i].type))
		{
			if (tkns[i].type == NORMAL)
				ft_printf(" normal");
			else if (tkns[i].type == SINGLE)
				ft_printf(" '");
			else if (tkns[i].type == DOUBLE)
				ft_printf(" \"");
			else if (tkns[i].type == LESS)
				ft_printf(" <");
			else if (tkns[i].type == GREAT)
				ft_printf(" >");
			else if (tkns[i].type == DLESS)
				ft_printf(" <<");
			else if (tkns[i].type == DGREAT)
				ft_printf(" >>");
			ft_printf("\t|  ");
			print_word(tkns[i].head, tkns[i].tail);
			ft_printf("\n");
		}
		else
		{
			if (tkns[i].type == AND_IF)
				ft_printf(" &&");
			else if (tkns[i].type == OR_IF)
				ft_printf(" ||");
			else if (tkns[i].type == PIPE)
				ft_printf(" |");
			ft_printf("\t|\n");
		}
		i++;
	}
	ft_printf("====================\n\n");
}

void	print_tkns_easy(t_tkn *tkns)
{
	size_t	i;

	i = 0;
	while (tkns[i].type != TAIL)
	{
		if (i)
			ft_printf(" ");
		if (type_is_word(tkns[i].type))
			print_word(tkns[i].head, tkns[i].tail);
		else if (tkns[i].type == LESS)
			ft_printf("<");
		else if (tkns[i].type == GREAT)
			ft_printf(">");
		else if (tkns[i].type == DLESS)
			ft_printf("<<");
		else if (tkns[i].type == DGREAT)
			ft_printf(">>");
		i++;
	}
}

void	print_cmds(t_cmd_a *cmds)
{
	size_t	i;

	i = 0;
	ft_printf(" ");
	while (cmds[i].tkns)
	{
		if (i)
			ft_printf(", ");
		ft_printf("[");
		print_tkns_easy(cmds[i].tkns);
		i++;
		ft_printf("]");
	}
	ft_printf("\n");
}

void	print_conds(t_cond *conds)
{
	size_t	i;

	ft_printf("[conds]\n");
	if (!conds)
		return ((void)ft_printf("NULL\n"));
	ft_printf("====================\n");
	ft_printf(" =type=\t| =content=\n");
	ft_printf("========|===========\n");
	i = 0;
	while (conds[i].type != TAIL)
	{
		if (conds[i].type == AND_IF)
			ft_printf(" &&\t|");
		else if (conds[i].type == OR_IF)
			ft_printf(" ||\t|");
		else if (conds[i].type == HEAD)
			ft_printf(" head\t|");
		else
			return ((void)ft_printf("%d is else!!!!!\n", conds[i].type));
		print_cmds(conds[i].cmds);
		i++;
	}
	ft_printf("====================\n\n");
}
