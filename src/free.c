/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:49:03 by akremer           #+#    #+#             */
/*   Updated: 2019/10/01 18:13:16 by lyhamrou         ###   ########.fr       */
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

void		free_handle(t_info *handle)
{
	free_combo(handle);
//	free_graph(handle->graph);
	free_room(handle);
	free_best(handle);
}

void			free_graph(t_graph *g)
{
	int		i;
	t_node	*n;
	t_node	*tmp;
	t_path	*tmp_p;
	t_path	*p;

	i = 0;
	if (g->tab_neigh)
	{
		while (i < g->nb_vertices)
		{
			n = g->tab_neigh[i].begin;
			p = g->tab_neigh[i].path;
			while (n)
			{
				tmp = n;
				n = n->next;
				free(tmp);
			}
			while (p)
			{
				tmp_p = p;
				free(p->path);
				p = p->next;
				free(tmp_p);
			}
			i++;
		}
		free(g->tab_neigh);
	}
	free(g);
}
