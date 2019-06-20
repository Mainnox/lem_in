/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:18:30 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 08:40:11 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void			ft_display_hastag_u(t_printf *h, unsigned long long nb,
		unsigned int ba, int len)
{
	int ch;

	ch = 0;
	if (h->extra->precision == 0 && nb == 0 && ba == 8)
		ch = 1;
	if ((nb == 0 || (ba == 8 && h->extra->precision > len))
			&& ch != 1)
		;
	else
		ft_print_hastag(h, 'c', ba);
}

void				ft_f_u(t_printf *h, char *base,
		unsigned int ba, unsigned long long nb)
{
	int		nbdisplay;
	int		len;

	len = ft_nbrlen(nb, 0, ba);
	if (nb == 0 && h->extra->precision == 0)
		len = 0;
	nbdisplay = ft_cal_nbdisplay(h, len, ba, nb);
	if (h->extra->precision != -1)
		h->extra->zero = -1;
	if (h->extra->moins == -1 && h->extra->zero == -1)
		ft_print_while(h, h->extra->width - nbdisplay, ' ');
	if (h->extra->hastag == 1)
		ft_display_hastag_u(h, nb, ba, len);
	if (h->extra->precision != -1)
		ft_print_while(h, h->extra->precision - len, '0');
	if (h->extra->zero == 1 && h->extra->moins == -1
			&& h->extra->precision == -1)
		ft_print_while(h, h->extra->width - nbdisplay, '0');
	if (h->extra->precision == 0 && nb == 0)
		;
	else
		ft_display_unsigned(h, base, ba, nb);
	if (h->extra->moins == 1)
		ft_print_while(h, h->extra->width - nbdisplay, ' ');
}
