/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:32:28 by akremer           #+#    #+#             */
/*   Updated: 2019/11/11 22:06:03 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		fill_print(t_info *handle, int i, int j)
{
	int	tw;

	tw = 1;
	handle->print.pasu[i][0] = handle->graph->combo[j][1] - 1;
	while (tw <= handle->print.pasu[i][0])
	{
		handle->print.pasu[i][tw] = handle->graph->combo[j][tw + 2];
		tw++;
	}
}

static void		set_print_helper(t_info *handle)
{
	if (handle->best->size_best == 0)
		handle->best->size_best = 1;
	if (!(handle->print.pasu = (int**)
				malloc(sizeof(int*) * handle->best->size_best)))
		free_at_print(handle);
	if (!(handle->print.pos_ants = (int**)
				malloc(sizeof(int*) * handle->best->size_best)))
		free_at_print(handle);
	handle->print.ant = 1;
	handle->print.nb_ants = handle->nb_ants;
	handle->print.flow = handle->best->size_best;
	handle->print.max_flow = handle->best->size_best;
}

int				set_print(t_info *handle)
{
	int				i;
	int				j;

	i = 0;
	set_print_helper(handle);
	while (i < handle->best->size_best)
	{
		j = 0;
		while (j < handle->graph->tab_neigh[1].nb_path)
		{
			if (handle->best->best[i] == handle->graph->combo[j][0])
			{
				if (!(handle->print.pasu[i] = (int*)
							malloc(sizeof(int) * handle->graph->combo[j][1])))
					free_at_print(handle);
				if (!(handle->print.pos_ants[i] = (int*)ft_memalloc(sizeof(
									int) * (handle->graph->combo[j][1] - 1))))
					free_at_print(handle);
				fill_print(handle, i, j);
				break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}
