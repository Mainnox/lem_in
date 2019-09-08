/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:43:41 by akremer           #+#    #+#             */
/*   Updated: 2019/09/08 11:24:46 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int			check_ban(int *ban, int ban_man)
{
	int i;

	i = 1;
	while (i <= ban[0])
	{
		if (ban[i] == ban_man)
			return (0);
		i++;
	}
	return (1);
}

static int			who_is_the_vip(t_graph *g, int *ban, int best)
{
	int		i;
	int		vip;
	int		size_vip;

	size_vip = -1;
	vip = -1;
	i = 0;
	while (i < g->tab_neigh[1].nb_path - 1)
	{
		if (size_vip <= g->combo[i][1] && check_ban(ban, i) && g->combo[i][1] > best)
		{
			size_vip = g->combo[i][1];
			vip = i;
		}
		i++;
	}
	ban[0]++;
	ban[ban[0]] = vip;
	return (vip);
}

static void			u_are_the_one(t_graph *g, int index)
{
	int		vip;
	int		i;
	int		*ban;

	if (!(ban = (int*)malloc(sizeof(int) * g->tab_neigh[1].nb_path)))
		return ;
	ban[0] = 1;
	ban[ban[0]] = index;
	i = 0;
	g->best[0]++;
	g->best[g->best[0]] = index;
	while (42)
	{
		vip = who_is_the_vip(g, ban, g->best[0]);
		ft_printf("vip = %d\n", vip);
		if (vip == -1)
			break ;
	}
	ft_printf("index = %d\n", index);
}

void				best_combo_ever(t_graph *g)
{
	int		i;

	i = 0;
	if (!(g->best = (int*)malloc(sizeof(int) * g->tab_neigh[1].nb_path + 1)))
		return ;
	g->best[0] = 0;
	while (i < g->tab_neigh[1].nb_path)
	{
		if (i == g->max_flow)
			u_are_the_one(g, i);
		i++;
	}
}
