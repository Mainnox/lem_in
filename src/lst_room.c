/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 11:11:46 by akremer           #+#    #+#             */
/*   Updated: 2019/08/31 16:40:02 by akremer          ###   ########.fr       */
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
	if (verif_room(handle, room) || verif_split(room->x, room->y, white))
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

int		lycos(t_info *handle, char *str)
{
	t_room	*tmp;

	tmp = handle->room;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (-1);
}

static void		clean_split(char **split)
{
	char	*tmp;
	int		i;

	i = 0;
	while (split[i])
	{
		tmp = ft_strtrim(split[i]);
		free(split[i]);
		split[i] = tmp;
		i++;
	}
}

int				new_edge(t_info *handle, char *s)
{
	int		mid;
	char	**split;
	int		i;

	i = 0;

	split = ft_strsplit(s, '-');
	clean_split(split);
	if (split[0][0] == '#')
	{
		ft_freesplit(split);
		return (0);
	}
	if (ft_splitlen(split) != 2)
	{
		ft_freesplit(split);
		return (1);
	}
	if (add_edge(handle->graph, lycos(handle, split[0]), lycos(handle, split[1])))
	{
		ft_freesplit(split);
		return (1);
	}
	ft_freesplit(split);
	return (0);
}
