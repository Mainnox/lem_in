/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 07:02:24 by akremer           #+#    #+#             */
/*   Updated: 2019/03/22 12:17:48 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	ft_print_printf_extra(t_printf *h)
{
	if (h->str[h->i] == 'p' && h->extra->done == -1)
	{
		h->extra->hastag = 1;
		h->extra->size = 6;
		ft_print_unsigned(h, 16);
	}
	if (h->str[h->i] == 'U' && h->extra->done == -1)
	{
		h->extra->size = 3;
		ft_print_unsigned(h, 10);
	}
	if (h->str[h->i] == 'D' && h->extra->done == -1)
	{
		h->extra->size = 3;
		ft_print_signed(h, 10);
	}
	if (h->str[h->i] == 'O' && h->extra->done == -1)
	{
		h->extra->size = 3;
		ft_print_unsigned(h, 8);
	}
	if (h->str[h->i] == 'f' && h->extra->done == -1)
		ft_print_float(h);
}

void		ft_print_printf(t_printf *h)
{
	if (h->str[h->i] == 'c' && h->extra->done == -1)
		ft_print_c(h, va_arg(h->ap, unsigned*));
	if (h->str[h->i] == 's' && h->extra->done == -1)
		ft_print_s(h, va_arg(h->ap, unsigned*));
	if ((h->str[h->i] == 'd' || h->str[h->i] == 'i') && h->extra->done == -1)
		ft_print_signed(h, 10);
	if (h->str[h->i] == 'o' && h->extra->done == -1)
		ft_print_unsigned(h, 8);
	if (h->str[h->i] == 'u' && h->extra->done == -1)
		ft_print_unsigned(h, 10);
	if (h->str[h->i] == 'x' && h->extra->done == -1)
		ft_print_unsigned(h, 16);
	if (h->str[h->i] == 'X' && h->extra->done == -1)
		ft_print_gx(h, 16);
	if (h->str[h->i] == '%' && h->extra->done == -1)
		ft_print_pc(h);
	if (h->extra->done == -1 && (h->str[h->i] == 'p'
			|| h->str[h->i] == 'U' || h->str[h->i] == 'D'
			|| h->str[h->i] == 'O' || h->str[h->i] == 'f'))
		ft_print_printf_extra(h);
}
