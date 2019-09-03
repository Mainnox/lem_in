/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:42:17 by akremer           #+#    #+#             */
/*   Updated: 2019/09/03 12:02:46 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

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
	ft_printf("Max_flow = %d\n", g->max_flow);
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

void		test_print_room(t_info handle)
{
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = handle.room;
	ft_printf("number of ants = %d\n", handle.nb_ants);
	while (tmp)
	{

		ft_printf("handle.room->name %3d = %10s\n", tmp->index, tmp->name);
		ft_printf("handle.room->x    %3d = %10d\n", tmp->index, tmp->x);
		ft_printf("handle.room->y    %3d = %10d\n", tmp->index, tmp->y);
		tmp = tmp->next;
		i++;
	}
//	ft_printf("EEEEEEEEEEEEEEEEEEEEEEEEET LE NOMBRE DE SALLES EST :\n");
//	sleep(1);
//	ft_printf("ROULEMENT DE TAMBOURS\n");
//	sleep(1);
	ft_printf("%d\n", handle.nb_room);
}

void		test_graph(void)
{
	t_graph		*g;

	g = new_graph(5);

	add_edge(g, 1, 2);
	ft_printf("casca\n");
	add_edge(g, 1, 4);
	add_edge(g, 0, 2);
	add_edge(g, 0, 4);
	add_edge(g, 4, 0);
	add_edge(g, 4, 3);
	add_edge(g, 0, 3);
	add_edge(g, 2, 3);
	print_graph(g);
	free_graph(g);
}
