/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 10:21:59 by akremer           #+#    #+#             */
/*   Updated: 2019/08/31 10:52:46 by akremer          ###   ########.fr       */
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
	n->path[size] = c;
	n->path[size + 1] = '\0';
	n->next = NULL;
	return (n);
}

static int			already_here(t_info *handle, char *rififi, int value)
{
	t_path		*src;

	src = handle->graph->tab_neigh[value].path;
	while (src)
	{
		if (ft_strcmp(src->path, rififi) == 0)
			return (1);
		src = src->next;
	}
	return (0);
}

static void			add_path(t_info *handle, char *path_src, int value)
{
	t_path	*n;

	n = create_path(ft_strlen(path_src), path_src, value + 48);
	if (already_here(handle, n->path, value))
	{
		free(n->path);
		free(n);
		return ;
	}
	n->next = handle->graph->tab_neigh[value].path;
	handle->graph->tab_neigh[value].path = n;
	if (value != 1)
		handle->graph->tab_neigh[value].done = 1;
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
			if (ft_strchr(path_src->path, adjacent->value + 48) == NULL)
				add_path(handle, path_src->path, adjacent->value);
			adjacent = adjacent->next;
		}
		path_src = path_src->next;
	}
}

static int			isnt_finish(t_graph *g)
{
	int i;

	i = 0;
	while (i < g->nb_vertices)
	{
		if (g->tab_neigh[i].done == 1)
			return (1);
		i++;
	}
	return (0);
}

int					resolve_lem_in(t_info *handle, char first)
{
	int			i;
	t_neigh		*tmp;

	i = 0;
	if (first)
	{
		handle->graph->tab_neigh[0].done = 1;
		if (!(handle->graph->tab_neigh[0].path = (t_path*)malloc(sizeof(t_path))))
			return (0);
		if (!(handle->graph->tab_neigh[0].path->path = (char*)malloc(sizeof(char) * 2)))
			return (0);
		handle->graph->tab_neigh[0].path->path[0] = '0';
		handle->graph->tab_neigh[0].path->path[1] = '\0';
		handle->graph->tab_neigh[0].path->next = NULL;
	}
	while (i < handle->graph->nb_vertices)
	{
		if (handle->graph->tab_neigh[i].done == 1)
			add_walkthrough(handle, i);
		i++;
	}
	if (isnt_finish(handle->graph) && first < 3)
		resolve_lem_in(handle, first + 1);
	return (0);
}
