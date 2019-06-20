/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 09:59:53 by akremer           #+#    #+#             */
/*   Updated: 2019/06/20 16:15:42 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int				ft_reset_extra(t_printf *h)
{
	if (h->extra)
		free(h->extra);
	if (!(h->extra = (t_extra *)malloc(sizeof(t_extra))))
		return (0);
	h->extra->plus = -1;
	h->extra->moins = -1;
	h->extra->hastag = -1;
	h->extra->precision = -1;
	h->extra->blanck = -1;
	h->extra->done = -1;
	h->extra->width = -1;
	h->extra->size = -1;
	h->extra->zero = -1;
	return (1);
}

static t_printf			*ft_create_struct(const char *format)
{
	t_printf *h;

	if (!(h = (t_printf *)malloc(sizeof(t_printf))))
		return (NULL);
	h->str = format;
	h->i = 0;
	h->nbprint = 0;
	h->extra = NULL;
	if (!ft_reset_extra(h))
		return (NULL);
	return (h);
}

int						ft_printf(const char *format, ...)
{
	t_printf	*h;

	h = ft_create_struct(format);
	va_start(h->ap, format);
	if (h == NULL)
		return (-1);
	while (h->str[h->i])
	{
		if (h->str[h->i] == '%')
		{
			h->i++;
			ft_flags_printf(h);
			if (!ft_reset_extra(h))
				return (-1);
			continue ;
		}
		ft_print_char(h, h->str[h->i]);
		h->i++;
	}
	free(h->extra);
	free(h);
	va_end(h->ap);
	return (h->nbprint);
}
