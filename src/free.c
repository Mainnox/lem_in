/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:49:03 by akremer           #+#    #+#             */
/*   Updated: 2019/11/11 03:48:38 by akremer          ###   ########.fr       */
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
	handle->best = NULL;
}

static void	free_path(t_info *handle)
{
	int 	i;
	t_path	*tmp;
	t_path	*tmp_free;

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

static void	free_print(t_info *handle)
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

int			free_handle(t_info *handle)
{
	int i;

	i = 0;
	free_combo(handle);
	free_room(handle);
	free_graph(handle->graph);
	free_print(handle);
	free_best(handle);
	return (1);
}

void		retry(t_info *handle)
{
	free_combo(handle);
	free_best(handle);
	free_path(handle);
	handle->tmp_nb_ants = handle->nb_ants > 1 ? handle->nb_ants + 1 : handle->nb_ants;
	handle->algo = 0;
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

void			quick_kill(void)
{
	write(2, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}
