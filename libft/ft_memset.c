/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:01:45 by akremer           #+#    #+#             */
/*   Updated: 2019/09/28 20:29:28 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*nstr;

	nstr = (char*)str;
	i = 0;
	while (i < n)
	{
		nstr[i] = c;
		i++;
	}
	return (str);
}
