/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 11:16:50 by akremer           #+#    #+#             */
/*   Updated: 2019/08/31 11:56:38 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_tabchr(int *tab, int rififi, int limit)
{
	int i;

	i = 0;
	while (tab[i] != limit)
	{
		if (tab[i] == rififi)
			return (i);
		i++;
	}
	return (-1);
}
