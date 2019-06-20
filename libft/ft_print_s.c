/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:55:51 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 08:40:08 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		ft_print_str(t_printf *h, char *str)
{
	h->nbprint += ft_strlen(str);
	write(1, str, ft_strlen(str));
}

static void	ft_print_pre(t_printf *h, char *str, int len)
{
	h->nbprint += len;
	write(1, str, len);
}

static int	ft_cal_len(t_printf *h, char *str)
{
	int len;

	len = ft_strlen(str);
	if (h->extra->precision != -1 && len > h->extra->precision)
		len = h->extra->precision;
	return (len);
}

void		ft_print_s(t_printf *h, unsigned *s)
{
	char	*str;
	int		len;

	len = 0;
	if (!(char *)s)
		str = "(null)";
	else
		str = (char *)s;
	len = ft_cal_len(h, str);
	if (h->extra->moins == -1 && h->extra->zero == -1)
		ft_print_while(h, h->extra->width - len, ' ');
	if (h->extra->zero == 1 && h->extra->moins == -1)
		ft_print_while(h, h->extra->width - len, '0');
	ft_print_pre(h, str, len);
	if (h->extra->moins == 1)
		ft_print_while(h, h->extra->width - len, ' ');
	h->i++;
	h->extra->done = 12;
}
