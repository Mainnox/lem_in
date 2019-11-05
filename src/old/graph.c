/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 09:32:07 by akremer           #+#    #+#             */
/*   Updated: 2019/10/01 17:45:20 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_graph(t_graph *g)
{
	int		i;
	t_node	*n;
	t_node	*tmp;
	t_path	*tmp_p;
	t_path	*p;

	i = 0;
	if (g->tab_neigh)
	{
		while (i < g->nb_vertices)
		{
			n = g->tab_neigh[i].begin;
			p = g->tab_neigh[i].path;
			while (n)
			{
				tmp = n;
				n = n->next;
				free(tmp);
			}
			while (p)
			{
				tmp_p = p;
				free(p->path);
				p = p->next;
				free(tmp_p);
			}
			i++;
		}
		free(g->tab_neigh);
	}
	free(g);
}

t_graph			*new_graph(int vertices)
{
	int		i;
	t_graph	*graph;

	i = 0;
	if (!(graph = (t_graph*)malloc(sizeof(t_graph))))
		return (NULL);
	graph->nb_vertices = vertices;
	if (!(graph->tab_neigh = (t_neigh*)malloc(sizeof(t_neigh) * vertices)))
		return (NULL);
	while (i < graph->nb_vertices)
	{
		graph->tab_neigh[i].done = 0;
		graph->tab_neigh[i].act_done = 0;
		graph->tab_neigh[i].path = NULL;
		graph->tab_neigh[i].begin = NULL;
		i++;
	}
	return (graph);
}

t_node			*add_node(int value)
{
	t_node	*n;

	if (!(n = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	n->value = value;
	n->next = NULL;
	return (n);
}

int				add_edge(t_info *handle, int src, int dest)
{
	t_node *n;

	if ((n = add_node(dest)) == NULL)
		return (0);
	n->next = handle->graph->tab_neigh[src].begin;
	handle->graph->tab_neigh[src].begin = n;
	if ((n = add_node(src)) == NULL)
		return (0);
	n->next = handle->graph->tab_neigh[dest].begin;
	handle->graph->tab_neigh[dest].begin = n;
	return (1);
}
