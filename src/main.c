/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:48:04 by akremer           #+#    #+#             */
/*   Updated: 2019/06/20 17:33:40 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			main(void)
{
	t_room		*rooms;
	char		**gnl;
	t_info		handle;
	int i;

	i = 0;
	if (!(gnl = (char **)malloc(sizeof(char*) * 1)))
		return (0);
	rooms = NULL;
	while (get_next_line(0, gnl) > 0)
	{
		if (i == 0)
		{
			handle.nb_ants = ft_atoi(gnl[0]);
			if (handle.nb_ants <= 0)
			{
				ft_printf("Number of ants sucks\n");
				free(gnl[0]);
				free(gnl);
				exit(0);
			}
		i++;
			ft_printf("nb_ants = %d\n", handle.nb_ants);
		}
//		else
//			store_room(rooms);
		free(gnl[0]);
	}
	return (0);
}
