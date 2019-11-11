/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:42:17 by akremer           #+#    #+#             */
/*   Updated: 2019/11/11 03:22:44 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		test_best(t_info *handle)
{
	int i;

	i = 0;
	ft_printf("Best = ");
	while (i < handle->best->size_best - 1)
	{
		ft_printf("%d-", handle->best->best[i]);
		i++;
	}
	ft_printf("%d\n", handle->best->best[i]);
}

void		test_rpasu(t_info *h)
{
	int		i;
	int		j;

	i = 0;
	ft_printf("\n___________________ test_rpasu _________________\n");
	ft_printf("rpasu :\n");
	while (i < h->print.max_flow)
	{
		j = 0;
		while (j < h->print.pasu[i][0])
		{
			ft_printf("%d-", h->visu.rpasu[i][j]);
			++j;
		}
		ft_printf("\n\n");
		++i;
	}
	ft_printf("________________________________________________\n\n");
}

void		test_visu(t_info *handle)
{
	t_visu visu;

	visu = handle->visu;
	ft_printf("\n___________________ test_visu _________________\n");
	ft_printf("x_min -> %d\n", visu.x_min);
	ft_printf("x_max -> %d\n", visu.x_max);
	ft_printf("y_min -> %d\n", visu.y_min);
	ft_printf("y_max -> %d\n\n", visu.y_max);
	ft_printf("nb_x -> %d\n", visu.nb_x);
	ft_printf("nb_y -> %d\n", visu.nb_y);
	ft_printf("pas -> %d\n", visu.pas);
	ft_printf("_______________________________________________\n");
}

void		test_pos_ants(t_print *out)
{
	int		i;
	int		j;

	i = 0;
	ft_printf("\n___________________ test_pos_ants _________________\n");
	ft_printf("ants --> %d\n", out->ant);
	while (i < out->max_flow)
	{
		j = 0;
		while (j < out->pasu[i][0])
			ft_printf("%d-", out->pos_ants[i][j++]);
		ft_printf("\n\n");
		++i;
	}
	ft_printf("_________________________________________________\n");
}

void		test_print(t_print *print)
{
	int i;
	int j;

	i = 0;
	ft_printf("_________ Test_print ____________\n");
	ft_printf("nb de ants    --> %d\n", print->nb_ants);
	ft_printf("ants          --> %d\n", print->ant);
	ft_printf("nb de chemins --> %d\n", print->max_flow);
	ft_printf("flow          --> %d\n", print->flow);
	ft_printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n");
	while (i < print->max_flow)
	{
		j = 1;
		ft_printf("chemin [%d]\n", i);
		ft_printf("size chemin = %d\n", print->pasu[i][0]);
		while (j < print->pasu[i][0])
		{
			ft_printf("%d-", print->pasu[i][j]);
			j++;
		}
		ft_printf("%d\n\n", print->pasu[i][j]);
		i++;
	}
	ft_printf("__________________________________\n");
}

int			test_banlist(int *banlist)
{
	int i;

	i = 0;
	ft_printf("Banlist = ");
	while (banlist[i] != 1)
	{
		ft_printf("%d-", banlist[i]);
		i++;
	}
	ft_printf("\n");
	return (1);
}

void		test_affiche_path(t_graph *g)
{
	t_path *tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < g->nb_vertices)
	{
		tmp = g->tab_neigh[i].path;
		while (tmp)
		{
			ft_printf("Sommet %d = ", i);
			j = 0;
			while (tmp->path[j + 1] != -1)
			{
				ft_printf("%d-", tmp->path[j]);
				j++;
			}
			ft_printf("%d\n", tmp->path[j]);
			tmp = tmp->next;
		}
		i++;
	}
}

void		test_size_path(t_graph *g)
{
	int		i;
	t_path	*tmp;

	i = 0;
	tmp = g->tab_neigh[1].path;
	while (tmp)
	{
		i = 0;
		ft_printf("Index = %d\nSize = %d\nPath = ", tmp->index, tmp->size);
		while (tmp->path[i + 1] != -1)
		{
			ft_printf("%d-", tmp->path[i]);
			i++;
		}
		ft_printf("%d\n", tmp->path[i], tmp->size);
		tmp = tmp->next;
	}
}

void		test_combo(t_graph *g)
{
	int i;
	int j;

	i = 0;
	while (i < g->tab_neigh[1].nb_path - 1)
	{
		ft_printf("Combo pour l'index [%d]\n", i);
		j = 0;
		while (g->combo[i][j] != -1)
		{
			ft_printf("[%d] = %d\n", j, g->combo[i][j]);
			j++;
		}
		i++;
	}
}

void		test_done(t_graph *g)
{
	int i;

	i = 0;
	while (i < g->nb_vertices)
	{
		ft_printf("g->tab_neigh[%d].done = %d\n", i, g->tab_neigh[i].done);
		i++;
	}
}

void		print_graph(t_info *handle)
{
	int		i;
	t_graph	*graph;
	t_node	*node;

	i = 0;
	graph = handle->graph;
	ft_printf("\n------------------- PRINT_GRAPH -----------------\n");
	ft_printf("nb_vertices --> %d\n", handle->graph->nb_vertices);
	ft_printf("------\n");
	while (i < graph->nb_vertices)
	{
	ft_printf("===============\n");
		node = graph->tab_neigh[i].begin;
		ft_printf("index - %d\n", i);
		while (node)
		{
			ft_printf("value %d\n", node->value);
			node = node->next;
		}
		++i;
		ft_printf("\n");
	}
	ft_printf("\n");
	ft_printf("--------------------------------------------------\n\n");
}

void		test_print_room(t_info handle)
{
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = handle.room;
	ft_printf("-----------------TEST PRINT ROOM---------------\n");
	ft_printf("number of ants = %d\n", handle.nb_ants);
	while (tmp)
	{
		ft_printf("handle.room->name %3d = %10s\n", tmp->index, tmp->name);
		ft_printf("handle.room->x    %3d = %10d\n", tmp->index, tmp->x);
		ft_printf("handle.room->y    %3d = %10d\n\n", tmp->index, tmp->y);
		tmp = tmp->next;
		i++;
	}
//	ft_printf("EEEEEEEEEEEEEEEEEEEEEEEEET LE NOMBRE DE SALLES EST :\n");
//	sleep(1);
//	ft_printf("ROULEMENT DE TAMBOURS\n");
//	sleep(1);
	ft_printf("%d\n", handle.nb_room);
	ft_printf("------------------------------------------\n");
}
