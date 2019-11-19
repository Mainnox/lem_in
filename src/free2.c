/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 06:35:50 by akremer           #+#    #+#             */
/*   Updated: 2019/11/19 01:07:03 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				free_gnl(char **buf, int i)
{
	ft_strdel(buf);
	return (i);
}

void			free_graph(t_graph *g)
{
	int		i;
	t_node	*n;
	t_node	*tmp;

	i = 0;
	if (g->tab_neigh)
	{
		while (i < g->nb_vertices)
		{
			n = g->tab_neigh[i].begin;
			while (n)
			{
				tmp = n;
				n = n->next;
				free(tmp);
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
