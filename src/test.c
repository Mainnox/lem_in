/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:42:17 by akremer           #+#    #+#             */
/*   Updated: 2019/08/31 12:54:51 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		test_affiche_path(t_graph *g)
{
	t_graph *tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tmp = g;
	while (i < tmp->nb_vertices)
	{
		while (tmp->tab_neigh[i].path)
		{
			ft_printf("Chemin %d = ", i);
			j = 0;
			while (g->tab_neigh[i].path->path[j + 1] != -1)
			{
				ft_printf("%d-", g->tab_neigh[i].path->path[j]);
				j++;
			}
			ft_printf("%d\n", g->tab_neigh[i].path->path[j]);
			tmp->tab_neigh[i].path = tmp->tab_neigh[i].path->next;
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
