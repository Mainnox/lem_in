/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:00:49 by akremer           #+#    #+#             */
/*   Updated: 2019/09/16 11:25:17 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			verif_start_end_exist(t_info *handle)
{
	if (handle->start == 2 && handle->end == 2)
		return (0);
	return (1);
}

int			verif_nb_ants(int nb_ants, char *gnl)
{
	char *tmp;
	int ret;

	ret = 0;
	tmp = ft_strtrim(gnl);
	if ((size_t)ft_nbrlen((unsigned long long)nb_ants, 0, 10) != ft_strlen(tmp))
	{
		ret++;
	}
	free(tmp);
	return (ret);
}

int			verif_split(int x, int y, char **split)
{
	int tmp;
	char signe;

	signe = (x < 0) ? 1 : 0;
	tmp = (x < 0) ? -x : x;
	if ((size_t)ft_nbrlen((unsigned long long)tmp, signe, 10) != ft_strlen(split[1]))
		return (1);
	signe = (y < 0) ? 1 : 0;
	tmp = (y < 0) ? -y : y;
	if ((size_t)ft_nbrlen((unsigned long long)tmp, signe, 10) != ft_strlen(split[2]))
		return (1);
	return (0);
}

int			verif_coor(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && i == 0)
			if (str[i] == '-' || str[i] == '+')
				i++;
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (i);
}

int			verif_room(t_info *handle, t_room *room)
{
	t_room		*tmp;

	tmp = handle->room;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, room->name) == 0)
			return (1);
		if (tmp->x == room->x && tmp->y == room->y)
			return (1);
		if (tmp->index == room->index)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			edge_exit(t_graph *g, int src, int dest)
{
	t_node *tmp;

	tmp = g->tab_neigh[src].begin;
	while (tmp)
	{
		if (tmp->value == dest)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
