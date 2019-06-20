/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:11:15 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 08:39:10 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*maillon;
	void	*ncontent;

	if (!(maillon = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		maillon->content = NULL;
		maillon->content_size = 0;
	}
	else
	{
		ncontent = ft_memalloc(content_size);
		ncontent = ft_memcpy(ncontent, content, content_size);
		maillon->content = ncontent;
		maillon->content_size = content_size;
	}
	maillon->next = NULL;
	return (maillon);
}
