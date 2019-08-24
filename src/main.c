/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:48:04 by akremer           #+#    #+#             */
/*   Updated: 2019/08/24 17:09:53 by akremer          ###   ########.fr       */
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
	handle->nb_room = 2;
	handle->room = NULL;
	return (gnl);	
}

static void	free_handle(t_info *handle)
{
	t_room *tmp;

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
	while (get_next_line(0, gnl) > 0)
	{
		if (i == 1)
		{
			handle.nb_ants = ft_atoi(gnl[0]);
			if (handle.nb_ants <= 0)
			{
				ft_printf("Number of ants sucks\n");
				free(gnl[0]);
					free(gnl);
				exit(0);
			}
		}
		else
			error = new_struct(&handle, gnl[0], i);
		free(gnl[0]);
		if (error)
			break ;
		i++;
	}
	test_print_room(handle);
	free_handle(&handle);
	return (0);
}
