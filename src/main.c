/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:48:04 by akremer           #+#    #+#             */
/*   Updated: 2019/09/27 18:12:01 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

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
	handle->print = NULL;
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
	test_print_room(handle);
	print_graph(handle.graph);
	if (handle.nb_ants > 1)
		handle.tmp_nb_ants = handle.nb_ants + 1;
	else
		handle.tmp_nb_ants = handle.nb_ants;
	resolve_lem_in(&handle, 1);
	test_affiche_path(handle.graph);
	seek_combo(handle.graph);
	best_combo(&handle);
	set_print(&handle);
	test_print(&handle);
	free_handle(&handle);
	return (0);
}
