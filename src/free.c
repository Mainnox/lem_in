/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:49:03 by akremer           #+#    #+#             */
/*   Updated: 2019/11/14 06:13:42 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_combo(t_info *handle)
{
	int		i;

	i = 0;
	while (i < handle->graph->tab_neigh[1].nb_path)
	{
		free(handle->graph->combo[i]);
		i++;
	}
	free(handle->graph->combo);
}

void	free_room(t_info *handle)
{
	t_room		*tmp;

	while (handle->room)
	{
		tmp = handle->room;
		handle->room = handle->room->next;
		free(tmp->name);
		free(tmp);
	}
}

void	free_best(t_info *handle)
{
	free(handle->best->tmp_best);
	free(handle->best->best);
	free(handle->best->banlist);
	free(handle->best);
	handle->best = NULL;
}

void	free_path(t_info *handle)
{
	int			i;
	t_path		*tmp;
	t_path		*tmp_free;

	i = 0;
	while (i < handle->graph->nb_vertices)
	{
		tmp = handle->graph->tab_neigh[i].path;
		while (tmp)
		{
			free(tmp->path);
			tmp_free = tmp;
			tmp = tmp->next;
			free(tmp_free);
		}
		handle->graph->tab_neigh[i].path = NULL;
		handle->graph->tab_neigh[i].mark = 0;
		handle->graph->tab_neigh[i].done = 0;
		handle->graph->tab_neigh[i].act_done = 0;
		handle->graph->tab_neigh[i].nb_path = 0;
		i++;
	}
}

void	free_print(t_info *handle)
{
	int		i;

	i = 0;
	while (i < handle->best->size_best)
	{
		free(handle->print.pasu[i]);
		free(handle->print.pos_ants[i]);
		i++;
	}
}
