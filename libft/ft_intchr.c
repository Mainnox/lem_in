/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:40:05 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/10/01 16:04:53 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_intchr(char const *s, char const *accept)
{
	int	i;
	int	j;

	i = 0;
	if (s && accept)
	{
		while (s[i] != '\0')
		{
			j = 0;
			while (accept[j] != '\0')
			{
				if (accept[j] == s[i])
					return (i);
				++j;
			}
			++i;
		}
	}
	return (-1);
}
