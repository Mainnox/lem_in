/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:22:37 by akremer           #+#    #+#             */
/*   Updated: 2019/03/23 17:15:09 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ndest;
	unsigned char	*nsrc;
	size_t			i;
	unsigned char	rififi;

	rififi = (unsigned char)c;
	ndest = (unsigned char*)dest;
	nsrc = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		ndest[i] = nsrc[i];
		if (ndest[i] == rififi)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
