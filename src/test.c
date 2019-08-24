/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:42:17 by akremer           #+#    #+#             */
/*   Updated: 2019/08/24 15:22:52 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		test_print_room(t_info handle)
{
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = handle.room;
	ft_printf("number of ants = %d\n", handle.nb_ants);
	while (tmp)
	{

		ft_printf("handle.room->name %3d = %10s\n", tmp->index, tmp->name);
		ft_printf("handle.room->x    %3d = %10d\n", tmp->index, tmp->x);
		ft_printf("handle.room->y    %3d = %10d\n", tmp->index, tmp->y);
		tmp = tmp->next;
		i++;
	}
	ft_printf("EEEEEEEEEEEEEEEEEEEEEEEEET LE NOMBRE DE SALLES EST :\n");
	sleep(1);
	ft_printf("ROULEMENT DE TAMBOURS\n");
	sleep(1);
	ft_printf("%d\n", handle.nb_room);
}
