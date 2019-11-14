/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:20:40 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/11/14 06:06:38 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	affect_index(t_info *handle, int start, int end, t_room *room)
{
	if (handle->start == 1 && start == 1)
	{
		room->index = 0;
		handle->start--;
	}
	else if (handle->end == 1 && end == 1)
	{
		room->index = 1;
		handle->end--;
	}
	else
		room->index = handle->i++;
}

void	room_to_handle(t_room *room, t_info *handle, t_room *tmp)
{
	if (handle->room == NULL)
		handle->room = room;
	else
	{
		tmp = handle->room;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = room;
	}
}

int		store_the_room(t_info *handle, char **buf, int start, int end)
{
	int		i;
	t_room	*room;
	t_room	*tmp;

	i = 0;
	room = NULL;
	tmp = NULL;
	if (!(room = (t_room *)ft_memalloc(sizeof(t_room))))
		return (0);
	affect_index(handle, start, end, room);
	i = skip_space(*buf, i);
	room->name = ft_strsub(*buf, i, ft_strchr(*buf, ' ') - *buf);
	i = skip_word(*buf, i);
	i = skip_space(*buf, i);
	room->x = ft_atoi(*buf + i);
	i = skip_word(*buf, i);
	room->y = ft_atoi(*buf + i);
	room_to_handle(room, handle, tmp);
	handle->nb_room++;
	return (1);
}

int		pars_room(t_info *handle, char **buf, int start, int end)
{
	int		i;

	while (get_next_line(0, buf) > 0)
	{
		i = ft_intchr(*buf, "-");
		if (i != -1 && c(handle, *buf, 0) == 0)
			return (start == 1 && end == 1 ? 1 : 0);
		else if (*buf[0] == 'L' || (i != -1 && c(handle, *buf, 0) == -1))
			return (free_gnl(buf, 0));
		if (ft_strcmp(*buf, "##start") == 0 || ft_strcmp(*buf, "##end") == 0)
		{
			ft_strcmp(*buf, "##end") == 0 ? end++ : start++;
			ft_strcmp(*buf, "##end") == 0 ? handle->end++ : handle->start++;
			ft_strdel(buf);
			continue ;
		}
		else if (*buf[0] == '#' && ft_strdel(buf))
			continue ;
		else if (count_arg(*buf) == 0 || start > 1 || end > 1)
			return (free_gnl(buf, 0));
		if (store_the_room(handle, buf, start, end) == 0)
			return (free_gnl(buf, 0));
		ft_strdel(buf);
	}
	return (start != 1 || end != 1 ? 0 : 1);
}
