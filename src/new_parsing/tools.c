/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:39:18 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/09/26 17:06:07 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*name_of_index(t_info *handle, int index)
{
	t_room	*tmp;

	tmp = handle->room;
	while (tmp)
	{
		if (tmp->index == index)
			return (tmp->name);
		tmp = tmp->next;
	}
	return (NULL);
}

int		index_of_name(t_info *handle, char *str)
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

t_room		*find_room_index(t_room *room, int index)
{
	t_room	*tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->index == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_room		*find_room_name(t_room *room, char *name)
{
	t_room	*tmp;

	tmp = room;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
//	ft_printf("\n");
