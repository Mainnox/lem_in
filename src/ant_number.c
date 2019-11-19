/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 03:35:23 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/11/19 03:43:20 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		store_ants_number(t_info *handle, char **buf, int i)
{
	if (*buf[i] >= '0' && *buf[i] <= '9')
	{
		if (ft_atoi(*buf) != ft_atol(*buf)
			|| (handle->nb_ants = ft_atoi(*buf)) <= 0
			|| (long)handle->nb_ants != ft_atol(*buf))
		{
			ft_strdel(buf);
			return (0);
		}
		ft_strdel(buf);
		return (1);
	}
	ft_strdel(buf);
	return (0);
}
