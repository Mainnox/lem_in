/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:24:22 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 17:27:29 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_atoi(const char *str)
{
	long		i;
	long		nega;
	long		result;

	nega = 1;
	result = 0;
	i = 0;
	if (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
				|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				nega = -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + str[i] - 48;
			i++;
		}
	}
	return (result * nega);
}
