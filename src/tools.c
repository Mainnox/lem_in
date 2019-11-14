/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:39:18 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/11/14 06:13:31 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*seek_this_room(int i, int j, t_room *tmp1, t_info *h)
{
	while (tmp1 && tmp1->index != h->print.pasu[i][j])
		tmp1 = tmp1->next;
	return (tmp1);
}

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
	int		i;
	t_room	*tmp;

	tmp = handle->room;
	if (!str)
		return (-1);
	str = str + skip_space(str, 0);
	i = ft_strlen(str) - 1;
	while (ft_isblank(str[i]) == 1)
		--i;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, str, i + 1) == 0)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (-1);
}

t_room	*find_room_index(t_room *room, int index)
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

t_room	*find_room_name(t_room *room, char *name)
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
