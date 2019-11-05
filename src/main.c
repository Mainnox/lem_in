/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:48:04 by akremer           #+#    #+#             */
/*   Updated: 2019/11/05 18:08:21 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	usage(int ac, char **av, t_info *handle)
{
	if (ac > 2)
	{
		ft_printf("usage: ./lem-in [-v] < [map_name]");
		return (0);
	}
	else if (ac == 2 && ft_strcmp(av[1], "-v") == 0)
		handle->init_visu = 1;
	return (1);
}

static void	setup_handle(t_info *handle)
{
	handle->init_visu = 0;
	handle->i = 2;
	handle->start = 0;
	handle->end = 0;
	handle->graph = NULL;
	handle->nb_room = 0;
	handle->room = NULL;
	handle->tmp_nb_ants = 0;
	handle->best = NULL;
}

static int	handle_freezer(t_info *handle, int boul)
{
	t_room *tmp;

	if (boul == 0)
		ft_printf("ERROR\n");
	while (handle->room)
	{
		tmp = handle->room;
		handle->room = handle->room->next;
		free(tmp->name);
		free(tmp);
	}
	return (EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
	int			nb_ants;
	t_info		handle;

	setup_handle(&handle);
	if (usage(ac, av, &handle) == 0)
		return (0);
	if (parsing(&handle) == 0)
		return (handle_freezer(&handle, 0));
	nb_ants = handle.nb_ants;
	handle.tmp_nb_ants = nb_ants > 1 ? nb_ants + 1 : nb_ants;
	resolve_lem_in(&handle, 0);
	seek_combo(handle.graph);
	best_combo(&handle);
	set_print(&handle);
	sim_ants(&handle);
	return (handle_freezer(&handle, 1));
}
