/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 10:21:59 by akremer           #+#    #+#             */
/*   Updated: 2019/11/19 01:11:01 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path		*create_path(size_t size, int *str, int c)
{
	t_path	*n;
	int		i;

	i = 0;
	if (!(n = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	if (!(n->path = (int*)malloc(sizeof(int) * size + 1)))
		return (NULL);
	ft_tabcpy(str, n->path, -1);
	n->size = 0;
	n->path[size - 1] = c;
	n->path[size] = -1;
	n->done = 1;
	n->next = NULL;
	return (n);
}

static void			add_path(t_info *handle, int *path_src, int value)
{
	t_path	*n;

	n = create_path(ft_tablen(path_src, -1), path_src, value);
	if (!n)
		free_at_combo(handle);
	n->next = handle->graph->tab_neigh[value].path;
	handle->graph->tab_neigh[value].path = n;
	handle->graph->tab_neigh[value].nb_path++;
	if (value != 1)
	{
		handle->graph->tab_neigh[value].act_done = 1;
		if (handle->fatty_fat == 1)
			handle->graph->tab_neigh[value].mark = 1;
	}
	else
		handle->algo = 1;
}

static void			add_walkthrough(t_info *handle, int i)
{
	t_node		*adjacent;
	t_path		*path_src;

	handle->graph->tab_neigh[i].done = 0;
	path_src = handle->graph->tab_neigh[i].path;
	while (path_src)
	{
		if (path_src->done == 1)
		{
			adjacent = handle->graph->tab_neigh[i].begin;
			while (adjacent)
			{
				if (handle->graph->tab_neigh[adjacent->value].mark == 0
						&& ft_tabchr(path_src->path, adjacent->value, -1) == -1)
					add_path(handle, path_src->path, adjacent->value);
				adjacent = adjacent->next;
			}
			path_src->done = 0;
		}
		else
			break ;
		path_src = path_src->next;
	}
}

static int			isnt_finish(t_graph *g)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (i < g->nb_vertices)
	{
		if (g->tab_neigh[i].act_done == 1)
		{
			ret++;
			g->tab_neigh[i].done = 1;
			g->tab_neigh[i].act_done = 0;
		}
		i++;
	}
	return (ret);
}

int					resolve_lem_in(t_info *handle, char first)
{
	int			i;

	i = -1;
	if (!first)
	{
		handle->graph->tab_neigh[0].done = 1;
		if (!(handle->graph->tab_neigh[0].path = (t_path*)
					malloc(sizeof(t_path))))
			free_at_combo(handle);
		if (!(handle->graph->tab_neigh[0].path->path = (int*)
					malloc(sizeof(int) * 2)))
			free_at_combo(handle);
		handle->graph->tab_neigh[0].path->path[0] = 0;
		handle->graph->tab_neigh[0].path->path[1] = -1;
		handle->graph->tab_neigh[0].path->done = 1;
		handle->graph->tab_neigh[0].path->next = NULL;
	}
	while (++i < handle->graph->nb_vertices && handle->tmp_nb_ants)
		if (handle->graph->tab_neigh[i].done == 1)
			add_walkthrough(handle, i);
	if (handle->algo)
		handle->tmp_nb_ants--;
	if (isnt_finish(handle->graph))
		resolve_lem_in(handle, first + 1);
	return (0);
}
