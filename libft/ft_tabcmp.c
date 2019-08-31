/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 11:24:02 by akremer           #+#    #+#             */
/*   Updated: 2019/08/31 12:08:48 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_tabcmp(int *tab, int *tab2, int limit)
{
	int i;

	i = 0;
	while (tab[i] != limit && tab2[i] != limit)
	{
		if (tab[i] != tab2[i])
			return (tab[i] - tab2[i]);
		i++;
	}
	return (0);
}
