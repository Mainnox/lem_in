/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:38:32 by akremer           #+#    #+#             */
/*   Updated: 2019/11/11 04:16:54 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		setup_best(t_info *handle)
{
	t_best *best;

	if (!(best = (t_best*)malloc(sizeof(t_best))))
		free_at_best(handle);
	if (!(best->banlist = (int*)malloc(sizeof(int) * handle->graph->nb_vertices)))
		free_at_best(handle);
	if (!(best->best = (int*)malloc(sizeof(int) * handle->graph->tab_neigh[1].nb_path)))
		free_at_best(handle);
	if (!(best->tmp_best = (int*)malloc(sizeof(int) * handle->graph->tab_neigh[1].nb_path)))
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

static void		add_to_best(t_info *handle, int *to_add)
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

static char		are_u_better(t_info *handle)
{
	if (handle->best->size_best < handle->best->size_tmp_best)
		return (1);
	else if (handle->best->size_best == handle->best->size_tmp_best)
	{
		if (handle->best->size_long > handle->best->size_long_tmp)
			return (1);
	}
	return (0);
}

static void		tmp_is_better(t_info *handle)
{
	int		i;
	char	better;

	better = are_u_better(handle);
	i  = 0;
	if (better)
	{
		while (i < handle->best->size_tmp_best)
		{
			handle->best->best[i] = handle->best->tmp_best[i];
			i++;
		}
		handle->best->size_best = handle->best->size_tmp_best;
		handle->best->size_long = handle->best->size_long_tmp;
	}
}

static void		besuto_shinu(t_info *handle)
{
	int		benri_datta;
	int		size_to_del;
	int		i;

	size_to_del = 0;
	i = 0;
	benri_datta = handle->best->tmp_best[handle->best->size_tmp_best - 1];
	while (i < handle->graph->tab_neigh[1].nb_path)
	{
		if (handle->graph->combo[i][0] == benri_datta)
		{
			size_to_del = handle->graph->combo[i][1] - 2;
			break ;
		}
		i++;
	}
	handle->best->banlist[handle->best->size_banlist - size_to_del - 1] = 1;
	handle->best->size_banlist -= size_to_del;
	handle->best->size_tmp_best--;
	handle->best->size_long_tmp -= size_to_del;
}

static void		omoshiroi_puroguramu(t_info *handle, int i)
{
	while (i < handle->graph->tab_neigh[1].nb_path - 1)
	{
		if (combo_match(handle->graph->combo[i], handle->best->banlist))
		{
			add_to_best(handle, handle->graph->combo[i]);
			omoshiroi_puroguramu(handle, i + 1);
			tmp_is_better(handle);
			besuto_shinu(handle);
			if (handle->nb_room > 1000)
				handle->best->juju++;
		}
		if (handle->best->juju >= 1)
			break;
		i++;
	}
}

int				best_combo(t_info *handle)
{
	int		i;

	i = 0;
	if (setup_best(handle))
		return (1);
	omoshiroi_puroguramu(handle, 0);
	return (0);
}
