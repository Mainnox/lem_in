/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:43:16 by akremer           #+#    #+#             */
/*   Updated: 2019/05/20 11:18:52 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			*ndest;
	const int	*nsrc;

	ndest = (int*)dest;
	nsrc = (const int*)src;
	if (n == 0 || ndest == nsrc)
		return (dest);
	while (n--)
		*ndest++ = *nsrc++;
	return (dest);
}
