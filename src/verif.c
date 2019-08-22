/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:00:49 by akremer           #+#    #+#             */
/*   Updated: 2019/08/22 11:36:45 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

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

int			verif_room(t_info handle, t_room *room)
{
	t_room		*tmp;

	tmp = handle.room;
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
