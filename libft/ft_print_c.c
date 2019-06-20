/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 07:12:06 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 08:39:38 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		ft_print_char(t_printf *h, char c)
{
	h->nbprint++;
	write(1, &c, 1);
}

void		ft_print_char2(char c)
{
	write(1, &c, 1);
}

void		ft_print_c(t_printf *h, unsigned *c)
{
	if (h->extra->moins == -1 && h->extra->zero == -1)
		ft_print_while(h, h->extra->width - 1, ' ');
	if (h->extra->zero == 1 && h->extra->moins == -1)
		ft_print_while(h, h->extra->width - 1, '0');
	ft_print_char(h, (char)c);
	if (h->extra->moins == 1)
		ft_print_while(h, h->extra->width - 1, ' ');
	h->extra->done = 12;
	h->i++;
}
