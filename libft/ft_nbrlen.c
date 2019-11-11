/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 10:08:45 by akremer           #+#    #+#             */
/*   Updated: 2019/11/10 23:30:53 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_nbrlen(unsigned long long nb, char signe, unsigned int ba)
{
	int ret;

	ret = 1;
	if (signe == 1)
		ret++;
	while (nb >= ba)
	{
		nb /= ba;
		ret++;
	}
	return (ret);
}
