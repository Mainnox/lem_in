/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:26:25 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/09/28 17:14:56 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	output(t_print *out)
{
	int		i;
	int		j;

	i = 0;
	while (i < out->size)
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
	(void)out;
}

int		calc_flow(int *size, int **pasu, int nb_ants)
{
	int		i;
	int		lim;//a suppr

	i = 0;
	lim = 0;
	ft_printf("calc_flow---------\n");
	while (i < *size - 1)
	{
		ft_printf("lim ---> %d\n", lim);
		lim += pasu[*size - 1][0] - pasu[i][0] + 1;
		ft_printf("lim ---> %d\n", lim);
		if (nb_ants < lim)
		{
			*size -= 1;
			i = -1;
			lim = 0;
			ft_printf("calc_flow nb_ants>lim\n");
		}
		++i;
	}
	return (lim);
}

void	sim_ants(t_info *handle)
{
	int		lim;//nb de fourmis limit avant laquelle on recalcule le flow
	t_print	out;

	out = handle->print;
	ft_printf("\n\n\n\n\n\n\n----------------------------------------------\n");
	lim = calc_flow(&out.size, out.pasu, out.nb_ants);
	ft_printf("lim  = %d\n", lim);
	ft_printf("size = %d\n", out.size);
	test_print(out);
	while (out.nb_ants > 0)
	{
		if (out.nb_ants < lim)
			lim = calc_flow(&out.size, out.pasu, out.nb_ants);
		push_swap(&out);
		output(&out);
		out.nb_ants -= out.size;
		exit(0);
	}
}
