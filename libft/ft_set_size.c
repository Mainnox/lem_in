/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 10:05:25 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 08:41:00 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void		ft_set_h(t_printf *h)
{
	while (42)
	{
		if (h->str[h->i] == 'h')
		{
			h->i++;
			if (h->str[h->i] == 'h')
			{
				if (h->extra->size < 1)
					h->extra->size = 1;
				h->i++;
				break ;
			}
			if (h->extra->size < 2)
				h->extra->size = 2;
			break ;
		}
	}
}

void			ft_set_l(t_printf *h)
{
	while (42)
	{
		if (h->str[h->i] == 'l')
		{
			h->i++;
			if (h->str[h->i] == 'l')
			{
				if (h->extra->size < 4)
					h->extra->size = 4;
				h->i++;
				break ;
			}
			if (h->extra->size < 3)
				h->extra->size = 3;
			break ;
		}
	}
}

void			ft_set_size(t_printf *h)
{
	while (42)
	{
		if (h->str[h->i] == 'h')
		{
			ft_set_h(h);
			break ;
		}
		if (h->str[h->i] == 'l')
		{
			ft_set_l(h);
			break ;
		}
		if (h->str[h->i] == 'j')
			if (h->extra->size < 5)
				h->extra->size = 5;
		if (h->str[h->i] == 'z')
			if (h->extra->size < 7)
				h->extra->size = 7;
		h->i++;
		break ;
	}
}
