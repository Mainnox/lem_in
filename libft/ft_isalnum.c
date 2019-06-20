/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:57:39 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 08:38:38 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_isalnum(int c)
{
	unsigned char rififi;

	rififi = (unsigned char)c;
	if (ft_isalpha(c) + ft_isdigit(c) > 0)
		return (1);
	return (0);
}
