/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:54:54 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 08:39:05 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstiter(t_list *alst, void (*f)(t_list *new))
{
	if (!alst || !f)
		return ;
	while (alst)
	{
		f(alst);
		alst = alst->next;
	}
}
