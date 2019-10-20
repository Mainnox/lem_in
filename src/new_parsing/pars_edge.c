/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_edge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:20:49 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/10/21 00:45:37 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		reverse_connect_storage(t_info *handle, int i1, int i2)
{
	t_room	*tmp;

	tmp = handle->room;
	while (tmp)
	{
		if (tmp->index == i2)
		{
			tmp->n_conect++;
			tmp->connect[tmp->n_conect - 1] = i1;
			return ;
		}
		tmp = tmp->next;
	}
}

int			init_connection(t_info *handle)
{
	t_room	*tmp;

	tmp = handle->room;
	while (tmp)
	{
		tmp->n_conect = 0;
		if (!(tmp->connect = (int *)malloc(sizeof(int) * handle->nb_room)))
		{
			//free_connect(handle->connect);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

static int	check_add_edge(char *buf, t_info *handle)
{
	int		i;
	char	*room;
	t_room	*tmp;

	tmp = handle->room;
	if (ft_strchr(buf, '-') != ft_strrchr(buf, '-'))
		return (0);
	i = ft_strchr(buf, '-') - buf;
	if (!(room = ft_strsub(buf, 0, i)))
		return (0);
	if ((tmp = find_room_name(handle->room, room)) == NULL)
		return (0);
	if (!(room = ft_strsub(buf, i + 1, ft_strlen(buf) - i - 1)))
		return (0);
	if ((i = index_of_name(handle, room)) == -1)
		return (0);
	tmp->n_conect++;
	tmp->connect[tmp->n_conect - 1] = i;
	reverse_connect_storage(handle, tmp->index, index_of_name(handle, room));
	room ? ft_strdel(&room) : 1;
	return (1);
}

int			pars_edge(t_info *handle, char **buf)
{
	(void)handle;
	(void)buf;
	if (init_connection(handle) == 0)
		return (0);
	if (check_add_edge(*buf, handle) == 0)
		return (0);
	while (get_next_line(0, buf) > 0)
	{
		if (ft_strcmp(*buf, "##start") == 0 || ft_strcmp(*buf, "##end") == 0)
			return (0);
		else if (*buf[0] == '#')
			continue ;
		else if (check_add_edge(*buf, handle) == 0)
			return (0);
	}
	return (1);
}
//ft_printf("\n");
