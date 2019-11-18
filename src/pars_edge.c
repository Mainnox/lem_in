/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_edge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:20:49 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/11/18 23:52:31 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			init_graph(t_info *handle)
{
	int		i;
	t_graph	*g;

	i = 0;
	if (!(g = (t_graph *)malloc(sizeof(t_graph))))
		return (0);
	g->nb_vertices = handle->nb_room;
	if (!(g->tab_neigh = (t_neigh *)ft_memalloc(sizeof(t_neigh)
		* handle->nb_room)))
		return (0);
	while (i < handle->nb_room)
	{
		g->tab_neigh[i].done = 0;
		g->tab_neigh[i].act_done = 0;
		g->tab_neigh[i].path = NULL;
		g->tab_neigh[i].begin = NULL;
		++i;
	}
	handle->graph = g;
	return (1);
}

int			edge_exist(t_info *handle, char *room1, char *room2)
{
	int		src;
	int		dest;
	t_node	*tmp;

	src = index_of_name(handle, room1);
	dest = index_of_name(handle, room2);
	if (src == -1 || dest == -1)
		return (1);
	tmp = handle->graph->tab_neigh[src].begin;
	while (tmp)
	{
		if (tmp->value == dest)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	check_add_edge(char *buf, t_info *handle)
{
	int		i;
	char	*room1;
	char	*room2;

	i = 0;
	if (ft_strcmp(buf, "##start") == 0 || ft_strcmp(buf, "##end") == 0)
		return (0);
	else if (buf[0] == '#')
		return (2);
	if (!ft_strchr(buf, '-') || ft_strchr(buf, '-') != ft_strrchr(buf, '-'))
		return (0);
	buf = buf + skip_space(buf, i);
	if (!(room1 = ft_strsub(buf, 0, ft_strchr(buf, '-') - buf)))
		return (0);
	i = ft_strchr(buf, '-') - buf + 1;
	i = skip_space(buf, i);
	room2 = buf + i;
	if (ft_strcmp(room1, room2) == 0 && ft_strdel(&room1))
		return (0);
	if (edge_exist(handle, room1, room2) == 1 && ft_strdel(&room1))
		return (0);
	if (add_edge(handle, room1, room2) == 0)
		return (0);
	room1 ? ft_strdel(&room1) : 1;
	return (1);
}

int			pars_edge(t_info *handle, char **buf)
{
	int		ret;

	ret = 0;
	if (init_graph(handle) == 0)
		return (0);
	if (check_add_edge(*buf, handle) == 0)
		return (free_gnl(buf, 0));
	ft_printf("WECH ALORS : %s\n", *buf);
	ft_strdel(buf);
	while (get_next_line(0, buf) > 0)
	{
		ret = check_add_edge(*buf, handle);
		if (ret == 2)
		{
			ft_strdel(buf);
			continue ;
		}
		else if (ret == 0)
			return (free_gnl(buf, 0));
		ft_strdel(buf);
	}
	return (1);
}
