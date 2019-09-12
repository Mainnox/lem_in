/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:38:32 by akremer           #+#    #+#             */
/*   Updated: 2019/09/12 11:34:43 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int		setup_best(t_info *handle)
{
	if (!(handle->best = (t_best*)malloc(sizeof(t_best))))
		return (1);
	if (!(handle->best->banlist = (int*)malloc(sizeof(int) * handle->graph->nb_vertices - 1)))
		return (1);
	if (!(handle->best->best = (int*)malloc(sizeof(int) * handle->graph->tab_neigh[1].nb_path)))
		return (1);
	if (!(handle->best->tmp_best = (int*)malloc(sizeof(int) * handle->graph->tab_neigh[1].nb_path)))
		return (1);
	handle->best->size_best = 0;
	handle->best->banlist[0] = 1;
	handle->best->size_banlist = 1;
	handle->best->size_tmp_best = 0;
	return (0);
}

static void		add_to_best(t_info handle, int *to_add)
{
	int		i;
	int		j;

	i = handle->best->size_best - 1;
	j = 3;
	while (to_add[j] != 1)
	{
		handle->best->banlist[i] = to_add[j];
		i++;
		j++;
	}
	handle->best->banlist[i] = 1;
	handle->best->size_banlist = i + 1;
	handle->best->tmp_best[handle->best->size_tmp_best] = to_add[0];
	handle->best->size_tmp_size++;
}

static void		tmp_is_better(t_info *handle)
{
	int		i;
	char	better;

	better = (handle->best->size_best < handle->best->size_tmp_best) ? 1 : 0;
	i  = 0;
	while (i < handle->best->size_tmp_best)
	{
		if (better)
			handle->best->best[i] = handle->best->tmp_best[i];
		handle->best->tmp_best[i] = 0;
		i++;
	}
	if (better)
		handle->best->size_best = handle->best->size_tmp_best;
	handle->best->
}

static void		omoshiroi_puroguramu(t_info *handle, int i)
{
	while (i < handle->graph->tab_neigh[1].nb_path - 1)
	{
		if (combo_match(handle->graph->combo[i], handle->best->banlist))
		{
			add_to_best(handle, handle->graph->combo[i]);
			omoshiroi_puroguramu(handle, ++i);
			tmp_is_better(handle);
			besuto_shinu(handle, handle->graph->combo[i]);
		}
		i++;
	}	
}

int				best_combo(t_info *handle)
{
	if (setup_best(handle))
		return (1);
	omoshiroi_puroguramu(handle, 0);
	ft_printf("Puroguramu ni kaeru !\n");
	return (0);
}
