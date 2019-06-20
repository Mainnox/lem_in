/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 07:56:55 by akremer           #+#    #+#             */
/*   Updated: 2019/03/22 11:50:39 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_cal_p(t_printf *h, int len, char c, unsigned int ba)
{
	if (h->extra->precision > len)
		len = h->extra->precision;
	if (h->extra->hastag == 1 && c == 'X')
		len += 2;
	else if (h->extra->hastag == 1 && ba == 16)
		len += 2;
	else if (h->extra->hastag == 1)
		len++;
	return (len);
}

int			ft_cal_nbdisplay(t_printf *h, int len,
		unsigned int ba, unsigned long long nb)
{
	if (h->extra->precision > len)
	{
		len = h->extra->precision;
		if (ba == 8)
			return (len);
	}
	if (nb != 0)
	{
		if (h->extra->hastag == 1 && ba == 16)
			len += 2;
		else if (h->extra->hastag == 1)
			len++;
	}
	return (len);
}

int			ft_cal_nbdisplay_signed(t_printf *h, int len, char signe)
{
	if (h->extra->precision > len)
		len = h->extra->precision;
	if (signe == 0 && (h->extra->blanck == 1 || h->extra->plus == 1))
		len++;
	return (len);
}

void		ft_print_hastag(t_printf *h, char c, unsigned int ba)
{
	if (c == 'X')
		ft_print_str(h, "0X");
	else if (ba == 16)
		ft_print_str(h, "0x");
	else
		ft_print_char(h, '0');
}

void		ft_print_signe(t_printf *h, char signe)
{
	if (signe == 1)
		ft_print_char(h, '-');
	else if (h->extra->plus == 1)
		ft_print_char(h, '+');
	else if (h->extra->blanck == 1)
		ft_print_char(h, ' ');
}
