/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 23:05:21 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/11/18 23:57:41 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		count_arg(char *buf)
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

int		c(t_info *handle, char *buf, int i)
{
	t_room	*tmp;

	tmp = handle->room;
	if (buf[0] == '#')
		return (1);
	else if (buf[0] == '-')
		return (-1);
	i = ft_strchr(buf, '-') - buf + 1;
	i = skip_space(buf, i);
	while (tmp)
	{
		if (ft_strncmp(tmp->name, buf + i, ft_strlen(tmp->name)) == 0)
			return (0);
		tmp = tmp->next;
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
	char	*tmp;

	i = 0;
	if (get_next_line(0, &tmp) != 1 || ft_strlen(tmp) == 0)
		return (0);
	while (tmp[0] == '#')
	{
		get_next_line(0, &tmp);
		*buf = ft_strdup(tmp);
	}
	*buf = tmp;
	free(tmp);
	*buf = *buf + skip_space(*buf, 0);
	if (*buf[i] == '+')
		++i;
	if (*buf[i] >= '0' && *buf[i] <= '9')
	{
		if (ft_atoi(*buf) != ft_atol(*buf)
			|| (handle->nb_ants = ft_atoi(*buf)) <= 0
			|| (long)handle->nb_ants != ft_atol(*buf))
			return (0);
		return (1);
	}
	return (0);
}

int		parsing(t_info *handle)
{
	char	*buf;

	if (ants_number(handle, &buf) == 0)
	{
		ft_strdel(&buf);
		return (0);
	}
	if (pars_room(handle, &buf, 0, 0) == 0)
	{
		ft_strdel(&buf);
		return (0);
	}
	if (check_room(handle) == 0)
	{
		ft_strdel(&buf);
		return (0);
	}
	if (pars_edge(handle, &buf) == 0)
	{
		ft_strdel(&buf);
		return (0);
	}
	buf != NULL ? ft_strdel(&buf) : 1;
	return (1);
}
