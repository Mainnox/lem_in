/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:38:32 by akremer           #+#    #+#             */
/*   Updated: 2019/09/16 11:41:14 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int		setup_best(t_info *handle)
{
	t_best *best;

	if (!(best = (t_best*)malloc(sizeof(t_best))))
		return (1);
	if (!(best->banlist = (int*)malloc(sizeof(int) * handle->graph->nb_vertices * 10)))
		return (1);
	if (!(best->best = (int*)malloc(sizeof(int) * handle->graph->tab_neigh[1].nb_path * 10)))
		return (1);
	if (!(best->tmp_best = (int*)malloc(sizeof(int) * handle->graph->tab_neigh[1].nb_path * 10)))
		return (1);
	best->size_best = 0;
	best->banlist[0] = 1;
	best->size_banlist = 1;
	best->size_tmp_best = 0;
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
	handle->best->size_banlist = i;
	handle->best->tmp_best[handle->best->size_tmp_best] = to_add[0];
	handle->best->size_tmp_best++;
}

static void		tmp_is_better(t_info *handle)
{
	int		i;
	char	better;

	//Check la taille aussi du plus long chemin pour faire la selection
	better = (handle->best->size_best < handle->best->size_tmp_best) ? 1 : 0;
	i  = 0;
	if (better)
	{
		while (i < handle->best->size_tmp_best)
		{
			handle->best->best[i] = handle->best->tmp_best[i];
			i++;
		}
		handle->best->size_best = handle->best->size_tmp_best;
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
	while (i < handle->graph->tab_neigh[1].nb_path - 1)
	{
		if (handle->graph->combo[i][0] == benri_datta)
		{
			size_to_del = handle->graph->combo[i][1] - 2;
			break ;
		}
		i++;
	}
	handle->best->banlist[handle->best->size_banlist - size_to_del] = 1;
	handle->best->size_banlist -= size_to_del;
	handle->best->size_tmp_best--;
}

static void		omoshiroi_puroguramu(t_info *handle, int i)
{
	while (i < handle->graph->tab_neigh[1].nb_path - 1)
	{
		if (combo_match(handle->graph->combo[i], handle->best->banlist))
		{
			add_to_best(handle, handle->graph->combo[i]);
			ft_printf("size_tmp_best after add = %d\n", handle->best->size_tmp_best);
			omoshiroi_puroguramu(handle, ++i);
			tmp_is_better(handle);
			besuto_shinu(handle);
		}
		i++;
	}	
		ft_printf("size_best = %d\n", handle->best->size_best);
}

int				best_combo(t_info *handle)
{
	int		i;

	ft_printf("------------------------------------------->>>>>\n");
	i = 0;
	if (setup_best(handle))
		return (1);
	omoshiroi_puroguramu(handle, 0);
	while (i < handle->best->size_best)
	{
		ft_printf("%d-", handle->best->best[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("Puroguramu ni kaeru !\n");
	return (0);
}
