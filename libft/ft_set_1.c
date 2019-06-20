/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 10:03:56 by akremer           #+#    #+#             */
/*   Updated: 2019/05/20 19:59:40 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			ft_set_moins(t_printf *h)
{
	h->extra->moins = 1;
	h->i++;
}

void			ft_set_blanck(t_printf *h)
{
	h->i++;
	h->extra->blanck = 1;
}

void			ft_set_precision(t_printf *h)
{
	h->i++;
	h->extra->precision = ft_atoi_printf(h);
	if (h->str[h->i] == '*')
	{
		h->extra->precision = (int)va_arg(h->ap, unsigned *);
		if (h->extra->precision < 0)
			h->extra->precision = -1;
		if (h->extra->precision == -4)
			h->extra->precision = 0;
		h->i++;
		return ;
	}
	if (h->extra->precision != -4)
		h->i += ft_nbrlen((unsigned long long)h->extra->precision, 0, 10);
	if (h->extra->precision == -4)
		h->extra->precision = 0;
}

void			ft_set_zero(t_printf *h)
{
	h->i++;
	h->extra->zero = 1;
}

void			ft_set_width(t_printf *h)
{
	h->extra->width = ft_atoi_printf(h);
	h->i += ft_nbrlen((unsigned long long)h->extra->width, 0, 10);
}
