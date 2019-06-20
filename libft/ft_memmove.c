/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:32:47 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 08:39:26 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ndest;
	char	*nsrc;
	size_t	i;

	ndest = (char*)dest;
	nsrc = (char*)src;
	i = 0;
	if (ndest > nsrc)
		while (n--)
			ndest[n] = nsrc[n];
	else
	{
		while (i < n)
		{
			ndest[i] = nsrc[i];
			i++;
		}
	}
	return (dest);
}
