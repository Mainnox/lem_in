/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:27:41 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 08:42:09 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strmapi(char const *src, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	i;

	i = 0;
	if (!src)
		return (NULL);
	if (!(dest = (char*)malloc(sizeof(*dest) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[i])
	{
		dest[i] = f(i, src[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
