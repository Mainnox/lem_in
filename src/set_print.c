/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:32:28 by akremer           #+#    #+#             */
/*   Updated: 2019/09/27 18:15:16 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		fill_print(t_info *handle, int i, int j)
{
	int		tw;

	tw = 1;
	handle->print->pasu[i][0] = handle->graph->combo[j][1] - 1;
	while (tw <= handle->print->pasu[i][0])
	{
		handle->print->pasu[i][tw] = handle->graph->combo[j][tw + 2];
		tw++;
	}
}

int				set_print(t_info *handle)
{
	int				i;
	int				j;

	i = 0;
	if (!(handle->print = (t_print*)malloc(sizeof(t_print))))
		return (1);
	if (!(handle->print->pasu = (int**)malloc(sizeof(int*) * handle->best->size_best)))
		return (1);
	if (!(handle->print->pos_ants = (int**)ft_memalloc(sizeof(int*) * handle->best->size_best)))
		return (1);
	while (i < handle->best->size_best)
	{
		j = 0;
		while (j < handle->graph->tab_neigh[1].nb_path)
		{
			if (handle->best->best[i] == handle->graph->combo[j][0])
			{
				if (!(handle->print->pasu[i] = (int*)malloc(sizeof(int) * handle->graph->combo[j][1])))
					return (1);
				if (!(handle->print->pos_ants[i] = (int*)malloc(sizeof(int) * handle->graph->combo[j][1] - 1)))
					return (1);
				fill_print(handle, i, j);
				break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}
