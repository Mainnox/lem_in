/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:36:12 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 08:42:34 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char			*str;
	int				i;
	unsigned char	rififi;

	str = (char*)s;
	rififi = (unsigned char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (str[i] == rififi)
			return (str + i);
		i--;
	}
	return (NULL);
}
