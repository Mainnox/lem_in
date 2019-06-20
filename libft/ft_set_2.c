/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 10:04:47 by akremer           #+#    #+#             */
/*   Updated: 2019/05/20 20:01:40 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		ft_set_hastag(t_printf *h)
{
	h->i++;
	h->extra->hastag = 1;
}

void		ft_set_plus(t_printf *h)
{
	h->i++;
	h->extra->plus = 1;
}

void		ft_set_star(t_printf *h)
{
	h->i++;
	h->extra->width = (int)va_arg(h->ap, unsigned *);
	if (h->extra->width < 0)
	{
		h->extra->width = -h->extra->width;
		h->extra->moins = 1;
	}
}
