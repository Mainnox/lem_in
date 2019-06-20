/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:33:44 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 08:38:53 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_taillenbr(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static void	remplisage(int n, char *str, int neg)
{
	int i;

	i = 0;
	while ((n * 10) / 10 != 0)
	{
		str[i] = n % 10 + 48;
		i++;
		n = n / 10;
	}
	if (neg == -1)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
}

char		*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		neg;

	neg = 1;
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = (char*)malloc(sizeof(*str) * (ft_taillenbr(n) + 1))))
		return (NULL);
	if (n < 0)
	{
		neg = -1;
		n = -n;
	}
	remplisage(n, str, neg);
	ft_strrev(str);
	return (str);
}
