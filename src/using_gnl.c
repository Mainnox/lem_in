/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 17:41:16 by akremer           #+#    #+#             */
/*   Updated: 2019/09/27 19:47:57 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				store_room(t_info *handle, char **gnl)
{
	char	error;
	char	change;

	change = 0;
	while (get_next_line(0, gnl) > 0)
	{
		if (handle->nb_room == 1)
		{
			handle->nb_room++;
			handle->nb_ants = ft_atoi(gnl[0]);
			if (handle->nb_ants <= 0 || verif_nb_ants(handle->nb_ants, gnl[0]))
			{
				free(gnl[0]);
				free(gnl);
				ft_printf("Number of ants suck\n");
				exit(0);
			}
		}
		else if (change == 0)
			error = new_struct(handle, gnl[0]);
		else
			error = new_edge(handle, gnl[0]);
		if (error && change == 0)
		{
			change++;
			error = 0;
			handle->graph = new_graph(handle->nb_room);
			if (!verif_start_end_exist(handle))
				error = new_edge(handle, gnl[0]);
			else
				error = 1;
		}
		free(gnl[0]);
		if (error)
			break ;
	}
}
