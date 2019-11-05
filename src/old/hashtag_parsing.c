/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtag_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 13:02:17 by akremer           #+#    #+#             */
/*   Updated: 2019/09/27 19:47:13 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			hashtag_parsing(char **str, t_info *handle)
{
	if (ft_strcmp("##start", str[0]) == 0)
	{
		if (handle->start != 0)
			return (0);
		handle->start = 1;
		if (ft_splitlen(str) != 1)
			return (0);
	}
	if (ft_strcmp("##end", str[0]) == 0)
	{
		if (handle->end != 0)
			return (0);
		handle->end = 1;
		if (ft_splitlen(str) != 1)
			return (0);
	}
	return (1);
}
