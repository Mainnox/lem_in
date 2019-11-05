#include "lem_in.h"

void	rotate_ants(t_print *out)
{
	int		i;
	int		j;

	i = out->max_flow - 1;
	while (i >= 0)
	{
		j = out->pasu[i][0] - 1;
		while (j > 0)
		{
			out->pos_ants[i][j] = out->pos_ants[i][j - 1];
			--j;
		}
		if (j == 0)
			out->pos_ants[i][0] = 0;
		--i;
	}
}

void	push_swap(t_print *out)
{
	int		i;

	i = 0;
	rotate_ants(out);
	while (i < out->flow && out->ant <= out->nb_ants)
	{
		out->pos_ants[i][0] = out->ant;
		out->ant++;
		++i;
	}
}
