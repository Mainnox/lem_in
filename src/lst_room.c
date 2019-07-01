/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 11:11:46 by akremer           #+#    #+#             */
/*   Updated: 2019/07/01 17:16:19 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			new_struct(t_info *handle, char *str)
{
	int i;
	t_room *tmp;
	t_room *room;

	i = ft_strclen(str, ' ');
	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (1);
	room->name = ft_strndup(str, i);
	room->x = ft_atoi(str + i + 1);
	room->y = ft_atoi(str + i + ft_nbrlen_clas(room->x) + 2);
	room->next = NULL;
	if (verif_room(*handle, room))
	{
		free(room->name);
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
