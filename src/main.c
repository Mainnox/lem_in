/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:48:04 by akremer           #+#    #+#             */
/*   Updated: 2019/09/02 11:45:54 by akremer          ###   ########.fr       */
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
	handle->graph = NULL;
	handle->nb_room = 1;
	handle->room = NULL;
	return (gnl);	
}

static void	free_handle(t_info *handle)
{
	t_room *tmp;

	free_graph(handle->graph);
	while (handle->room)
	{
		tmp = handle->room;
		handle->room = handle->room->next;
		free(tmp->name);
		free(tmp);
	}
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
	resolve_lem_in(&handle, 1);
	test_affiche_path(handle.graph);
	seek_combo(handle.graph);
	free_handle(&handle);
	return (0);
}
