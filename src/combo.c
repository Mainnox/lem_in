/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:26:23 by akremer           #+#    #+#             */
/*   Updated: 2019/08/31 18:04:22 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"


static void		set_size_path(t_graph *g)
{
	t_path *tmp;

	tmp = g->tab_neigh[1].path;
	while (tmp)
	{
		tmp->size = ft_tablen(tmp->path, -1);
		tmp = tmp->next;
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
	set_size_path(g);
	test_size_path(g);
	return (0);
}
