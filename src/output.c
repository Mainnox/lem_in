/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:26:25 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/10/04 19:42:59 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_finish(t_print *out)
{
	int		i;
	int		j;

	i = 0;
	if (out->ant < out->nb_ants)
		return (0);
	else
	{
		while (i < out->max_flow)
		{
			j = 0;
			while (j < out->pasu[i][j])
			{
				if (out->pos_ants[i][j] != 0)
					return (0);
				++j;
			}
			++i;
		}
	}
	return (1);
}

int		visu_n_end_check(t_print *out, t_info *handle)
{
	if (handle->init_visu != 0)
		visu(handle, out->ant);
	if (is_finish(out) == 0 && ft_printf("\n"))
	{
		return (0);
	}
	if (handle->init_visu != 0)
		mlx_loop(handle->visu.mlx);
	return (1);
}

int		output(t_print *out, t_info *handle)
{
	int		i;
	int		j;
	char	*name;

	j = out->pasu[out->max_flow - 1][0];
	while (j >= 0)
	{
		i = 0;
		while (i < out->max_flow)
		{
			if (j < out->pasu[i][0] && out->pos_ants[i][j] > 0)
			{
				name = name_of_index(handle, out->pasu[i][j + 1]);
				ft_printf("L%d-%s ", out->pos_ants[i][j], name);
			}
			++i;
		}
		--j;
	}
	return (visu_n_end_check(out, handle));
}

int		calc_flow(t_print *out)
{
	int		i;
	int		lim;

	i = 0;
	lim = 0;
	while (i < out->flow - 1)
	{
		lim += out->pasu[out->flow - 1][0] - out->pasu[i][0] + 1;
		if (out->nb_ants - out->ant <= lim)
		{
			out->flow--;
			i = 0;
			lim = 0;
		}
		++i;
	}
	return (lim);
}

void	sim_ants(t_info *handle)
{
	int		lim;
	t_print	out;

	out = handle->print;
	lim = calc_flow(&out);
	while (1)
	{
		if (out.nb_ants - out.ant < lim)
			lim = calc_flow(&out);
		push_swap(&out);
		if (output(&out, handle) == 1)
			break ;
	}
}
