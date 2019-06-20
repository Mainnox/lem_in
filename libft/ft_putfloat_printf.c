/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:34:35 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 08:40:28 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void			ft_after_print(t_printf *h, double f, unsigned long long nb)
{
	while (nb == 0 && h->extra->precision > 0)
	{
		f *= 10;
		nb = (unsigned long long)f;
		ft_print_char(h, '0');
		h->extra->precision--;
	}
	nb = 0;
	while (h->extra->precision != 1)
	{
		nb = nb * 10 + (unsigned long long)f;
		f -= (unsigned long long)f;
		h->extra->precision--;
	}
	nb = nb * 10 + (unsigned long long)f + 0.5;
	ft_display_unsigned(h, "0123456789", 10, nb);
}

static void			ft_putfloat_printf(double f, t_printf *h)
{
	unsigned long long nb;

	if (f < 0)
	{
		f = -f;
		ft_print_char(h, '-');
	}
	nb = (unsigned long long)f;
	ft_display_unsigned(h, "0123456789", 10, nb);
	if (h->extra->precision == -1)
		h->extra->precision = 6;
	if (h->extra->precision > 0)
	{
		ft_print_char(h, '.');
		f -= nb;
		f *= 10;
		nb = (unsigned long long)f;
		ft_after_print(h, f, nb);
	}
}

void				ft_print_float(t_printf *h)
{
	ft_putfloat_printf(va_arg(h->ap, double), h);
	h->extra->done = 12;
	h->i++;
}
