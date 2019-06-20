/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 13:38:30 by akremer           #+#    #+#             */
/*   Updated: 2019/05/20 19:58:34 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	ft_flags_set_1(t_printf *h)
{
	while (42)
	{
		if (h->extra->done == -1 && h->str[h->i] == '-')
		{
			ft_set_moins(h);
			continue;
		}
		if (h->extra->done == -1 && h->str[h->i] == '+')
		{
			ft_set_plus(h);
			continue;
		}
		if (h->extra->done == -1 && h->str[h->i] == '#')
		{
			ft_set_hastag(h);
			continue;
		}
		if (h->extra->done == -1 && h->str[h->i] == '.')
		{
			ft_set_precision(h);
			continue;
		}
		break ;
	}
}

static void	ft_flags_set_2(t_printf *h)
{
	while (42)
	{
		if (h->extra->done == -1 && h->str[h->i] == ' ')
		{
			ft_set_blanck(h);
			continue;
		}
		if (h->extra->done == -1 && h->str[h->i] == '*')
		{
			ft_set_star(h);
			continue;
		}
		if (h->extra->done == -1 && (h->str[h->i] >= '1'
					&& h->str[h->i] <= '9'))
		{
			ft_set_width(h);
			continue;
		}
		if (h->extra->done == -1 && h->str[h->i] == '0')
		{
			ft_set_zero(h);
			continue;
		}
		break ;
	}
}

static void	ft_flags_set_m(t_printf *h)
{
	while (42)
	{
		if (h->extra->done == -1 && (h->str[h->i] == '-'
				|| h->str[h->i] == '+' || h->str[h->i] == '#'
				|| h->str[h->i] == '.'))
		{
			ft_flags_set_1(h);
			continue ;
		}
		if (h->extra->done == -1 && (h->str[h->i] == ' ' || h->str[h->i] == '*'
				|| (h->str[h->i] >= '1' && h->str[h->i] <= '9')
				|| h->str[h->i] == '0'))
		{
			ft_flags_set_2(h);
			continue ;
		}
		if (h->extra->done == -1 && (h->str[h->i] == 'j'
				|| h->str[h->i] == 'h' || h->str[h->i] == 'l'
				|| h->str[h->i] == 'z'))
		{
			ft_set_size(h);
			continue;
		}
		break ;
	}
}

void		ft_flags_printf(t_printf *h)
{
	while (42)
	{
		ft_flags_set_m(h);
		if (h->extra->done == -1 && (h->str[h->i] == 'c'
				|| h->str[h->i] == 's' || h->str[h->i] == 'd'
				|| h->str[h->i] == 'i' || h->str[h->i] == 'o'
				|| h->str[h->i] == 'u' || h->str[h->i] == 'x'
				|| h->str[h->i] == 'X' || h->str[h->i] == '%'
				|| h->str[h->i] == 'p' || h->str[h->i] == 'D'
				|| h->str[h->i] == 'U' || h->str[h->i] == 'O'
				|| h->str[h->i] == 'f'))
			ft_print_printf(h);
		break ;
	}
}
