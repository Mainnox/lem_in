/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:26:25 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/09/28 21:04:50 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	output(t_print *out)
{
	int		i;
	int		j;

	i = 0;
	while (i < out->flow)
	{
		j = 0;
		while (j < out->pasu[i][0])
		{
			++j;
		}
		++i;
	}
}

void	push_swap(t_print *out)
{
	int		i;
	int		j;

	(void)out;
	i = 0;
	test_pos_ants(out);
	while (i < out->max_flow)
	{
		j = 0;
		while (j < out->pasu[i][0])
		{
			;
			++j;
		}
		++i;
	}
}

int		calc_flow(int *flow, int **pasu, int nb_ants)
{
	int		i;
	int		lim;//a suppr

	i = 0;
	lim = 0;
	while (i < *flow - 1)
	{
		lim += pasu[*flow - 1][0] - pasu[i][0] + 1;
		if (nb_ants < lim)
		{
			*flow -= 1;
			i = -1;
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
	ft_printf("\n\n\n\n----------------------------------------------\n");
	lim = calc_flow(&out.flow, out.pasu, out.nb_ants);
	ft_printf("lim  = %d\n", lim);
	ft_printf("flow = %d\n", out.flow);
	test_print(out);
	while (out.nb_ants > 0)
	{
		if (out.nb_ants < lim)
			lim = calc_flow(&out.flow, out.pasu, out.nb_ants);
		push_swap(&out);
		output(&out);
		out.nb_ants -= out.flow;
		exit(0);
	}
}
