/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:38:32 by akremer           #+#    #+#             */
/*   Updated: 2019/09/11 12:24:21 by akremer          ###   ########.fr       */
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

	i = handle->
}

static void		omoshiroi_puroguramu(t_info *handle, int i)
{
	while (i < handle->graph->tab_neigh[1].nb_path - 1)
	{
		if (combo_match(handle->graph->combo[i], handle->best->banlist))
		{
			add_to_best(handle, );
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
