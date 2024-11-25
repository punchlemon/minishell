/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tkns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:00:42 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/25 15:10:53 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
#include "ft_printf.h"

void	print_word(const char *head, const char *tail);

int	print_tkns_init(t_tkn *tkns)
{
	ft_printf("[tkns]\n");
	if (!tkns)
		return ((void)ft_printf("NULL\n"), 0);
	ft_printf("====================\n");
	ft_printf("=type=\t| =content=\n");
	ft_printf("========|===========\n");
	return (1);
}

void	print_tkns_cmd(t_tkn *tkn)
{
	if (tkn->type == NORMAL)
		ft_printf(" normal");
	else if (tkn->type == SINGLE)
		ft_printf(" '");
	else if (tkn->type == DOUBLE)
		ft_printf(" \"");
	else if (tkn->type == LESS)
		ft_printf(" <");
	else if (tkn->type == GREAT)
		ft_printf(" >");
	else if (tkn->type == DLESS)
		ft_printf(" <<");
	else if (tkn->type == DGREAT)
		ft_printf(" >>");
	ft_printf("\t|  ");
	print_word(tkn->head, tkn->tail);
	ft_printf("$\n");
}

void	print_tkns(t_tkn *tkns)
{
	size_t	i;

	if (!print_tkns_init(tkns))
		return ;
	i = 0;
	while (tkns[i].type != TAIL)
	{
		if (type_is_cmd(tkns[i].type))
			print_tkns_cmd(&tkns[i]);
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
