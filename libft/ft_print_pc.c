/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:53:08 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 08:40:06 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_print_pc(t_printf *h)
{
	if (h->extra->moins == -1 && h->extra->zero == -1)
		ft_print_while(h, h->extra->width - 1, ' ');
	if (h->extra->zero == 1 && h->extra->moins == -1)
		ft_print_while(h, h->extra->width - 1, '0');
	ft_print_char(h, '%');
	if (h->extra->moins == 1)
		ft_print_while(h, h->extra->width - 1, ' ');
	h->extra->done = 12;
	h->i++;
}
