/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:43:50 by akremer           #+#    #+#             */
/*   Updated: 2019/03/22 11:53:48 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			ft_display_unsigned(t_printf *h, char *base,
		unsigned int ba, unsigned long long nb)
{
	if (nb >= ba)
		ft_display_unsigned(h, base, ba, nb / ba);
	ft_print_char(h, base[nb % ba]);
}

void			ft_flags_p(t_printf *h, char *base,
		unsigned int ba, unsigned long long nb)
{
	int		nbdisplay;
	int		len;

	len = ft_nbrlen(nb, 0, ba);
	if (nb == 0 && h->extra->precision == 0)
		len = 0;
	nbdisplay = ft_cal_p(h, len, 'c', ba);
	if (h->extra->precision != -1)
		h->extra->zero = -1;
	if (h->extra->moins == -1 && h->extra->zero == -1)
		ft_print_while(h, h->extra->width - nbdisplay, ' ');
	if (h->extra->hastag == 1)
		ft_print_hastag(h, 'c', ba);
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

void			ft_print_signed(t_printf *h, int ba)
{
	char *base;

	base = "0123456789abcdef";
	if (h->extra->size == 1)
		ft_f_s(h, base, ba, (char)va_arg(h->ap, unsigned *));
	else if (h->extra->size == 2)
		ft_f_s(h, base, ba, (short)va_arg(h->ap, unsigned *));
	else if (h->extra->size == 3)
		ft_f_s(h, base, ba, (long)va_arg(h->ap, unsigned *));
	else if (h->extra->size == 4)
		ft_f_s(h, base, ba, (long long)va_arg(h->ap, unsigned *));
	else if (h->extra->size == 5)
		ft_f_s(h, base, ba, (intmax_t)va_arg(h->ap, unsigned *));
	else if (h->extra->size == 7)
		ft_f_s(h, base, ba, (ssize_t)va_arg(h->ap, unsigned *));
	else
		ft_f_s(h, base, ba, (int)va_arg(h->ap, unsigned *));
	h->i++;
	h->extra->done = 12;
}

void			ft_print_unsigned(t_printf *h, unsigned int ba)
{
	char *base;

	base = "0123456789abcdef";
	if (h->extra->size == 1)
		ft_f_u(h, base, ba, (unsigned char)va_arg(h->ap, unsigned *));
	else if (h->extra->size == 2)
		ft_f_u(h, base, ba, (unsigned short)va_arg(h->ap, unsigned *));
	else if (h->extra->size == 3)
		ft_f_u(h, base, ba, (unsigned long)va_arg(h->ap, unsigned *));
	else if (h->extra->size == 6)
		ft_flags_p(h, base, ba, (unsigned long)va_arg(h->ap, unsigned *));
	else if (h->extra->size == 4)
		ft_f_u(h, base, ba, (unsigned long long)va_arg(h->ap, unsigned *));
	else if (h->extra->size == 5)
		ft_f_u(h, base, ba, (uintmax_t)va_arg(h->ap, unsigned *));
	else if (h->extra->size == 7)
		ft_f_u(h, base, ba, (size_t)va_arg(h->ap, unsigned *));
	else
		ft_f_u(h, base, ba, (unsigned int)va_arg(h->ap, unsigned *));
	h->i++;
	h->extra->done = 12;
}

void			ft_print_gx(t_printf *h, unsigned int ba)
{
	char *base;

	base = "0123456789ABCDEF";
	if (h->extra->size == 1)
		ft_flags_gx(h, base, ba, (unsigned char)va_arg(h->ap, unsigned *));
	else if (h->extra->size == 2)
		ft_flags_gx(h, base, ba, (unsigned short)va_arg(h->ap, unsigned *));
	else if (h->extra->size == 3)
		ft_flags_gx(h, base, ba, (unsigned long)va_arg(h->ap, unsigned *));
	else if (h->extra->size == 4)
		ft_flags_gx(h, base, ba, (unsigned long long)va_arg(h->ap, unsigned *));
	else if (h->extra->size == 5)
		ft_flags_gx(h, base, ba, (uintmax_t)va_arg(h->ap, unsigned *));
	else if (h->extra->size == 7)
		ft_flags_gx(h, base, ba, (size_t)va_arg(h->ap, unsigned *));
	else
		ft_flags_gx(h, base, ba, (unsigned int)va_arg(h->ap, unsigned *));
	h->i++;
	h->extra->done = 12;
}
