/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:56:58 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 08:42:22 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	char	*tab;
	size_t	len;

	if (ft_strlen(str) > n)
		len = n;
	else
		len = ft_strlen(str);
	if (!(tab = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
