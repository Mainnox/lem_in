/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:26:23 by akremer           #+#    #+#             */
/*   Updated: 2019/09/02 12:09:25 by akremer          ###   ########.fr       */
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
}

static int		set_combo(t_graph *g)
{
	t_path	*tmp;

	tmp = g->tab_neigh[1].path;
	if (!(g->combo = (int**)malloc(sizeof(int*) * g->tab_neigh[1].nb_path)))
		return (1);
	while (tmp)
	{
		if (!(g->combo[tmp->index] = (int*)malloc(sizeof(int) * g->tab_neigh[1].nb_path + 2)))
			return (1);
		g->combo[tmp->index][0] = tmp->size;
		g->combo[tmp->index][1] = 2;
		g->combo[tmp->index][2] = -1;
		tmp = tmp->next;
	}
	return (0);
}

static int		combo_match(int *act, int *next)
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

static void		fill_combo(t_graph *g)
{
	t_path		*tmp_act;
	t_path		*tmp_next;

	tmp_act = g->tab_neigh[1].path;
	while (tmp_act->next)
	{
		tmp_next = tmp_act->next;
		while (tmp_next)
		{
			if (combo_match(tmp_act->path, tmp_next->path))
			{
				g->combo[tmp_next->index][g->combo[tmp_next->index][1]] = tmp_act->index;
				g->combo[tmp_act->index][g->combo[tmp_act->index][1]] = tmp_next->index;
				g->combo[tmp_act->index][1] = g->combo[tmp_act->index][1] + 1;
				g->combo[tmp_next->index][1] = g->combo[tmp_next->index][1] + 1;
				g->combo[tmp_next->index][g->combo[tmp_next->index][1]] = -1;
				g->combo[tmp_act->index][g->combo[tmp_act->index][1]] = -1;
			}
//			test_size_path(g);
//			test_combo(g);
//			sleep(5);
			tmp_next = tmp_next->next;
		}
		tmp_act = tmp_act->next;
	}
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
	fill_combo(g);
	test_combo(g);
	return (0);
}
