/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 06:37:05 by akremer           #+#    #+#             */
/*   Updated: 2019/11/19 01:21:13 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			free_handle(t_info *handle)
{
	free_combo(handle);
	free_room(handle);
	free_path(handle);
	free_graph(handle->graph);
	free_print(handle);
	free_best(handle);
	system("leaks lem-in");
	return (1);
}

void		retry(t_info *handle)
{
	free_combo(handle);
	free_best(handle);
	free_path(handle);
	handle->tmp_nb_ants = handle->nb_ants > 1 ? handle->nb_ants
		+ 1 : handle->nb_ants;
	handle->algo = 0;
}

void		free_at_combo(t_info *handle)
{
	free_room(handle);
	free_path(handle);
	free_graph(handle->graph);
	system("leaks lem-in");
	quick_kill();
}

void		free_at_best(t_info *handle)
{
	free_room(handle);
	free_combo(handle);
	free_graph(handle->graph);
	quick_kill();
}

void		free_at_print(t_info *handle)
{
	free_room(handle);
	free_combo(handle);
	free_best(handle);
	free_graph(handle->graph);
	quick_kill();
}
