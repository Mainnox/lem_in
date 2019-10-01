/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:48:04 by akremer           #+#    #+#             */
/*   Updated: 2019/10/01 14:46:22 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char		**setup_main(t_info *handle)
{
	char **gnl;

	if (!(gnl = (char **)malloc(sizeof(char*) * 1)))
		return (NULL);
	handle->start = 0;
	handle->end = 0;
	handle->algo = 0;
	handle->graph = NULL;
	handle->nb_room = 1;
	handle->room = NULL;
	handle->best = NULL;
	handle->tmp_nb_ants = 0;
	return (gnl);	
}

int			main(void)
{
	char		**gnl;
	t_info		handle;
	int 		i;
	char 		error;

	error = 0;
	i = 1;
	gnl = setup_main(&handle);
	if (!gnl)
		return (0);
	store_room(&handle, gnl);
	if (handle.nb_ants > 1)
		handle.tmp_nb_ants = handle.nb_ants + 1;
	else
		handle.tmp_nb_ants = handle.nb_ants;
	resolve_lem_in(&handle, 1);
	seek_combo(handle.graph);
	best_combo(&handle);
	set_print(&handle);
	sim_ants(&handle);
	free_handle(&handle);
	return (0);
}
