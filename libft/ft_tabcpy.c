/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 11:31:25 by akremer           #+#    #+#             */
/*   Updated: 2019/08/31 11:35:20 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			ft_tabcpy(int *src, int *dest, int limit)
{
	int i;

	i = 0;
	while (src[i] != limit)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = limit;
}
