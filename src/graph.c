/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 09:32:07 by akremer           #+#    #+#             */
/*   Updated: 2019/08/27 16:37:51 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void			print_graph(t_graph *g)
{
	int		i;
	t_node	*n;

	i = 0;
	while (i < g->nb_vertices)
	{
		n = g->tab_neigh[i].begin;
		ft_printf("(%d) : ", i);
		while (n)
		{
			ft_printf("%d, ", n->value);
			n = n->next;
		}
		i++;
		ft_printf("NULL\n");
	}
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

int				add_edge(t_graph *g, int src, int dest)
{
	t_node *n;
	
	if ((src == -1) || (dest == -1))
		return (1);
	n = add_node(dest);
	n->next = g->tab_neigh[src].begin;
	g->tab_neigh[src].begin = n;
	n = add_node(src);
	n->next = g->tab_neigh[dest].begin;
	g->tab_neigh[dest].begin = n;
	return (0);
}

void			free_graph(t_graph *g)
{
	int		i;
	t_node *n;
	t_node *tmp;

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
