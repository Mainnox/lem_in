/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:48:04 by akremer           #+#    #+#             */
/*   Updated: 2019/08/22 11:35:22 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			main(void)
{
	char		**gnl;
	t_info		handle;
	int 		i;
	char 		error;

	error = 0;
	i = 0;
	if (!(gnl = (char **)malloc(sizeof(char*) * 1)))
		return (0);
	handle.start = 0;
	handle.end = 0;
	handle.room = NULL;
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
		}
		else
			error = new_struct(&handle, gnl[0], i);
		free(gnl[0]);
		if (error)
			break ;
		i++;
	}
	test_print_room(handle);
	return (0);
}
