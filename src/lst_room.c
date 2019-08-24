/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 11:11:46 by akremer           #+#    #+#             */
/*   Updated: 2019/08/24 18:00:01 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			new_struct(t_info *handle, char *str)
{
	char	**white;
	t_room *tmp;
	t_room *room;

	white = ft_split_whitespace(str);
	if (white[0][0] == '#')
	{
		if (!hashtag_parsing(white, handle))
			return (1);
		return (0);
	}
	if (ft_splitlen(white) != 3)
	{
		ft_freesplit(white);
		return (1);
	}
	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (1);
	if (handle->start == 1)
	{
		room->index = 0;
		handle->start = 2;
	}
	else if (handle->end == 1)
	{
		room->index = 1;
		handle->end = 2;
	}
	else
		room->index = handle->nb_room++;
	room->name = ft_strdup(white[0]);
	room->x = ft_atoi(white[1]);
	room->y = ft_atoi(white[2]);
	room->next = NULL;
	if (verif_room(*handle, room))
	{
		free(room->name);
		handle->nb_room--;
		free(room);
		return (1);
	}
	if (handle->room == NULL)
		handle->room = room;
	else
	{
		tmp = handle->room;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = room;
	}
	return (0);
}
