/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 09:32:07 by akremer           #+#    #+#             */
/*   Updated: 2019/10/02 16:10:31 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node			*add_node(int value)
{
	t_node	*n;

	if (!(n = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	n->value = value;
	n->next = NULL;
	return (n);
}

int				add_edge(t_info *handle, char *room1, char *room2)
{
	int		src;
	int		dest;
	t_node *n;

	src = index_of_name(handle, room1);
	dest = index_of_name(handle, room2);
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
