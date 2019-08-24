/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 17:41:16 by akremer           #+#    #+#             */
/*   Updated: 2019/08/24 18:00:07 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void				store_room(t_info *handle, char **gnl)
{
	char	error;

	while (get_next_line(0, gnl) > 0)
	{
		if (handle->nb_room == 1)
		{
			handle->nb_room++;
			handle->nb_ants = ft_atoi(gnl[0]);
			if (handle->nb_ants <= 0)
			{
				free(gnl[0]);
				free(gnl);
				ft_printf("Number of ants suck\n");
				exit(0);
			}
		}
		else
			error = new_struct(handle, gnl[0]);
		free(gnl[0]);
		if (error)
			break ;
	}
}
