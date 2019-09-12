/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:26:23 by akremer           #+#    #+#             */
/*   Updated: 2019/09/12 11:18:55 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"


static void		set_path(t_graph *g)
{
	t_path	*tmp;
	int		i;

	i = 0;
	tmp = g->tab_neigh[1].path;
	while (tmp)
	{
		tmp->size = ft_tablen(tmp->path, -1) - 1;
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
	g->tab_neigh[1].nb_path = i + 1;
	g->max_flow = 0;
}

static int		set_combo(t_graph *g)
{
	t_path		*tmp;
	int			i;
	int			j;

	i = 0;
	tmp = g->tab_neigh[1].path;
	if (!(g->combo = (int**)ft_memalloc(sizeof(int*) * g->tab_neigh[1].nb_path)))
		return (1);
	while (tmp)
	{
		j = 0;
		if (!(g->combo[i] = (int*)ft_memalloc(sizeof(int) * (tmp->size + 3))))
			return (1);
		g->combo[i][0] = tmp->index;
		g->combo[i][1] = tmp->size;
		while (tmp->path[j] != -1)
		{
			g->combo[i][j + 2] = tmp->path[j];
			ft_printf("sommet dans combo %d\n", g->combo[i][j+2]);
			j++;
		}
		ft_printf("\n");
		g->combo[i][j + 2] = -1;
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int				combo_match(int *act, int *next)
{
	int		i;
	int		j;

	i = 1;
	while (act[i] != 1)
	{
		j = 1;
		while (next[j] != 1)
		{
			if (act[i] == next[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				seek_combo(t_graph *g)
{
	int		i;
	t_path	*tmp;

	tmp = g->tab_neigh[1].path;
	i = 1;
	if (!tmp)
		return (1);
	set_path(g);
	test_size_path(g);
	set_combo(g);
	sort_combo(g);
	test_combo(g);
	return (0);
}
