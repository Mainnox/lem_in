/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 06:07:23 by akremer           #+#    #+#             */
/*   Updated: 2019/11/11 06:20:31 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_to_best(t_info *handle, int *to_add)
{
	int		i;
	int		j;

	i = handle->best->size_banlist - 1;
	if (i < 0)
		i = 0;
	j = 3;
	while (to_add[j] != 1)
	{
		handle->best->banlist[i] = to_add[j];
		i++;
		j++;
	}
	handle->best->banlist[i] = 1;
	handle->best->size_banlist = i + 1;
	handle->best->size_long_tmp += to_add[1] - 2;
	handle->best->tmp_best[handle->best->size_tmp_best] = to_add[0];
	handle->best->size_tmp_best++;
}

int		setup_best(t_info *handle)
{
	t_best *best;

	if (!(best = (t_best*)malloc(sizeof(t_best))))
		free_at_best(handle);
	if (!(best->banlist = (int*)
				malloc(sizeof(int) * handle->graph->nb_vertices)))
		free_at_best(handle);
	if (!(best->best = (int*)
				malloc(sizeof(int) * handle->graph->tab_neigh[1].nb_path)))
		free_at_best(handle);
	if (!(best->tmp_best = (int*)
				malloc(sizeof(int) * handle->graph->tab_neigh[1].nb_path)))
		free_at_best(handle);
	best->juju = 0;
	best->size_best = 0;
	best->banlist[0] = 1;
	best->size_banlist = 1;
	best->size_tmp_best = 0;
	best->size_long_tmp = 0;
	best->size_long = 0;
	handle->best = best;
	return (0);
}
