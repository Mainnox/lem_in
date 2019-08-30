/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:42:17 by akremer           #+#    #+#             */
/*   Updated: 2019/08/30 14:45:59 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		test_affiche_path(t_graph *g)
{
	t_graph *tmp;
	int		i;

	i = 0;
	tmp = g;
	while (tmp->tab_neigh[1].path)
	{
		ft_printf("Chemin %d = %s\n", i , tmp->tab_neigh[1].path->path);
		tmp->tab_neigh[1].path = tmp->tab_neigh[1].path->next;
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
