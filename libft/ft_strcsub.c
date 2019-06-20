/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:33:49 by akremer           #+#    #+#             */
/*   Updated: 2019/05/19 17:45:56 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	count(const char *src, char c)
{
	int i;

	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char		*ft_strcsub(const char *src, char c)
{
	int		i;
	char	*dest;

	dest = NULL;
	i = 0;
	if (!src)
		return (NULL);
	if (!(dest = (char*)malloc(sizeof(*dest) * count(src, c) + 1)))
		return (NULL);
	while (src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
