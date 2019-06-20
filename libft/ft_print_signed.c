/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_signed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:22:10 by akremer           #+#    #+#             */
/*   Updated: 2019/03/22 11:50:52 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void			ft_display_signed(t_printf *h, char *base,
		int ba, long long nb)
{
	unsigned long long nbr;

	if (nb < 0)
		nbr = -nb;
	else
		nbr = nb;
	ft_display_unsigned(h, base, ba, nbr);
}

static void			ft_display_signed_space(t_printf *h, int nbdisplay
		, int len, char signe)
{
	if (h->extra->precision != -1)
		h->extra->zero = -1;
	if (h->extra->moins == -1 && h->extra->zero == -1)
		ft_print_while(h, h->extra->width - nbdisplay, ' ');
	ft_print_signe(h, signe);
	if (h->extra->precision != -1)
		ft_print_while(h, h->extra->precision - len, '0');
	if (h->extra->zero == 1 && h->extra->moins == -1
			&& h->extra->precision == -1)
		ft_print_while(h, h->extra->width - nbdisplay, '0');
}

void				ft_f_s(t_printf *h, char *base,
		unsigned int ba, long long nb)
{
	int		nbdisplay;
	char	signe;
	int		len;

	signe = (nb < 0) ? 1 : 0;
	nb = (nb < 0) ? -nb : nb;
	len = ft_nbrlen(nb, signe, ba);
	if (h->extra->precision != -1 && signe == 1)
		h->extra->precision += 1;
	if (nb == 0 && h->extra->precision == 0)
		len = 0;
	nbdisplay = ft_cal_nbdisplay_signed(h, len, signe);
	ft_display_signed_space(h, nbdisplay, len, signe);
	if (h->extra->precision == 0 && nb == 0)
		;
	else
		ft_display_signed(h, base, ba, nb);
	if (h->extra->moins == 1)
		ft_print_while(h, h->extra->width - nbdisplay, ' ');
}
