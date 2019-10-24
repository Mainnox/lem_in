/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:49:03 by akremer           #+#    #+#             */
/*   Updated: 2019/10/24 15:46:53 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	free_combo(t_info *handle)
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

static void	free_room(t_info *handle)
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

static void	free_best(t_info *handle)
{
	free(handle->best->tmp_best);
	free(handle->best->best);
	free(handle->best->banlist);
	free(handle->best);
}

static void	free_print(t_info *handle)
{
	int			i;

	i = 0;
	while (i < handle->best->size_best)
	{
		free(handle->print.pasu[i]);
		free(handle->print.pos_ants[i]);
		i++;
	}
	free(handle->print.pasu);
	free(handle->print.pos_ants);
}

void		free_handle(t_info *handle, char code)
{
	if (code > 2)
		free_combo(handle);
	if (code > 3)
		free_print(handle);
	if (code > 4)
		free_best(handle);
	if (code > 1)
	{
		free_graph(handle->graph);
		free_room(handle);
	}
}
