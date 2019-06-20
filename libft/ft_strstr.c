/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:37:39 by akremer           #+#    #+#             */
/*   Updated: 2019/03/23 20:25:48 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strstr(const char *s, const char *to)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*to_find;

	str = (char*)s;
	to_find = (char*)to;
	i = 0;
	if (ft_strlen(to_find) == 0)
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (j == ft_strlen(to_find) - 1)
				return (str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
