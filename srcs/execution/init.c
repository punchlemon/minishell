#include "minishell.h"

void	init_conds(t_cond *conds)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (conds[i].type != TAIL)
	{
		j = 0;
		while (conds[i].cmds[j].type != TAIL)
		{
			conds[i].cmds[j].pipe_in[0] = 0;
			conds[i].cmds[j].pipe_in[1] = -1;
			conds[i].cmds[j].pipe_out[0] = -1;
			conds[i].cmds[j].pipe_out[1] = 1;
			j++;
		}
		i++;
	}
}
