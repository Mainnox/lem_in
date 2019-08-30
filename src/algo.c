/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 10:21:59 by akremer           #+#    #+#             */
/*   Updated: 2019/08/30 13:31:22 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static t_path		*create_path(size_t size, char *str, char c)
{
	t_path	*n;

	if (!(n = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	if (!(n->path = (char*)malloc(sizeof(char) * size + 2)))
		return (NULL);
	ft_strcpy(n->path, str);
	n->path[size + 1] = c;
	n->path[size + 2] = '\0';
	n->next = NULL;
	return (n);
}

static void			add_path(t_info *handle, char *path_src, int value)
{
	t_path	*n;

	n = create_path(ft_strlen(path_src), path_src, value + 48);
	n->next = handle->graph->tab_neigh[value].path;
	handle->graph->tab_neigh[value].path = n;
}

static void			add_walkthrough(t_info *handle, int i)
{
	t_node		*adjacent;
	t_path		*path_src;
	t_path		*path_dest;
	int			find_it;

	find_it = 0;
	handle->graph->tab_neigh[i].done = 0;
	path_src = handle->graph->tab_neigh[i].path;
	while (path_src)
	{
		adjacent = handle->graph->tab_neigh[i].begin;
		while (adjacent)
		{
			if (ft_strchr(path_src->path, adjacent + 48 == NULL))
				add_path(handle, path_src->path, adjacent->value);
			adjacent = adjacent->next;
		}
		path_src = path_src->next;
	}
}

int					resolve_lem_in(t_info *handle, char first)
{
	int			i;
	t_neigh		*tmp;
	int			j;

	j = 0;
	i = 0;
	if (first)
	{
		handle->graph->tab_neigh[0].done = 1;
		handle->graph->tab_neigh[0].path = create_path(1, "", '0');
		if (!(handle->graph->tab_neigh[0].path->path = (char*)malloc(sizeof(char) * 2)))
			return (1);
		handle->graph->tab_neigh[0].path->path = "0\0";
	}
	while (i < handle->graph->nb_vertices)
	{
		if (handle->graph->tab_neigh[i].done == 1)
		{
			add_walkthrough(handle, i);
			j++;
		}
		i++;
	}
	if (j)
		resolve_lem_in(handle, 0);
	return (0);
}
