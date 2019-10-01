/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:42:17 by akremer           #+#    #+#             */
/*   Updated: 2019/09/26 17:06:44 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		printroom(t_info *handle)
{
	t_room	*tmp;
	int		i;

	tmp = handle->room;
	printf(VERT"\n\n------------------- ROOM -------------------\n"BLANC);
	printf("number of ants = %d\n", handle->nb_ants);
	printf(VERT"--------------------------------------------\n"BLANC);
	printf(JAUNE"___________________\n"BLANC);
	while (tmp)
	{
		i = 0;
		printf("room index = %d\n", tmp->index);
		printf("room name  = %s\n", tmp->name);
		printf("room x     = %d\n", tmp->x);
		printf("room y     = %d\n", tmp->y);
		printf("This room is connected to  %d  other room :\n", tmp->n_conect);
		while (i < tmp->n_conect)
		{
			printf("- index    = %d\n", tmp->connect[i]);
			++i;
		}
		tmp = tmp->next;
		printf(JAUNE"___________________\n\n"BLANC);
	}
	printf(VERT"--------------------------------------------\n"BLANC);
}
