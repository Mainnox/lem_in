/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:34:07 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 08:42:31 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strnstr(const char *s, const char *to, size_t n)
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
	while (str[i] && i < n)
	{
		j = 0;
		while (to_find[j] == str[i + j] && i + j < n)
		{
			if (j == ft_strlen(to_find) - 1)
				return (str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
