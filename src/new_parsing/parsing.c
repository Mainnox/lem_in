/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 23:05:21 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/10/21 00:45:55 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		arg_number(char *buf)
{
	int		i;
	int		arg;

	i = 0;
	arg = 0;
	while (buf[i])
	{
		while (ft_isblank(buf[i]) == 1)
			++i;
		if (buf[i] && ft_isblank(buf[i]) == 0)
		{
			while (buf[i] && ft_isblank(buf[i]) == 0)
				++i;
			++arg;
		}
	}
	return (arg != 3 ? 0 : 1);
}

int		check_less(char *buf, int i)
{
	int		len;

	len = (int)ft_strlen(buf);
	if (buf[0] == '#')
		return (1);
	else if (buf[0] == '-')
		return (-1);
	while (buf[i])
	{
		if (buf[i] == '-' && ft_isblank(buf[i - 1]) == 0)
			return (0);
		++i;
	}
	return (1);
}

int		check_room(t_info *handle)
{
	t_room	*room;
	t_room	*tmp;

	room = handle->room;
	tmp = handle->room;
	while (room->next)
	{
		tmp = handle->room;
		while (tmp)
		{
			if (tmp->index != room->index
				&& ft_strcmp(tmp->name, room->name) == 0)
				return (0);
			if (tmp->index != room->index
				&& tmp->x == room->x && tmp->y == room->y)
				return (0);
			tmp = tmp->next;
		}
		room = room->next;
	}
	return (1);
}

int		ants_number(t_info *handle, char **buf)
{
	int		i;

	i = 0;
	if (get_next_line(0, buf) != 1)
		return (0);
	while (*buf[0] == '#')
		get_next_line(0, buf);
	while (*buf[i])
	{
		if (*buf[i] != ' ' && *buf[i] != '-' && *buf[i] != '+'
			&& (*buf[i] < '0' || *buf[i] > '9'))
			return (0);
		if ((*buf[i] == '-' || *buf[i] == '+')
			&& (*buf[i + 1] < '0' || *buf[i + 1] > '9'))
			return (0);
		++i;
	}
	if ((handle->nb_ants = ft_atoi(*buf)) <= 0)
		return (0);
	return (1);
}

int		parsing(t_info *handle)
{
	char	*buf;

	buf = NULL;
	if (ants_number(handle, &buf) == 0)
		return (0);
	if (pars_room(handle, &buf, 0, 0) == 0)
		return (0);
	if (check_room(handle) == 0)
		return (0);
	if (pars_edge(handle, &buf) == 0)
		return (0);
	printroom(handle);
	buf != NULL ? ft_strdel(&buf) : 1;
	return (1);
}
//	printf("\n");
