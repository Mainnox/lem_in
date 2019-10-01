/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:48:04 by akremer           #+#    #+#             */
/*   Updated: 2019/09/25 20:04:31 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	setup_handle(t_info *handle)
{
	handle->i = 2;
	handle->start = 0;
	handle->end = 0;
	handle->graph = NULL;
	handle->nb_room = 0;
	handle->room = NULL;
}

static int	handle_freezer(t_info *handle)
{
	t_room *tmp;

	while (handle->room)
	{
		tmp = handle->room;
		handle->room = handle->room->next;
		free(tmp->name);
		free(tmp);
	}
	return (EXIT_SUCCESS);
}

int		main(void)
{
	t_info		handle;

	setup_handle(&handle);
	if (parsing(&handle) == 0)
		return (handle_freezer(&handle));
	return (handle_freezer(&handle));
}
//	printf("\n");
