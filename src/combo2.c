/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:32:26 by akremer           #+#    #+#             */
/*   Updated: 2019/09/11 10:38:27 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void			sort_combo(t_graph *g)
{
	int			i;
	int			j;
	int			*tmp;

	i = 0;
	while (i < g->tab_neigh[1].nb_path - 2)
	{
		j = i + 1;
		while (j < g->tab_neigh[1].nb_path - 1)
		{
			if (g->combo[i][0] > g->combo[j][0])
			{
				tmp = g->combo[i];
				g->combo[i] = g->combo[j];
				g->combo[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
