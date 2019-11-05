/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_octant_bresenham.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:31:39 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/08/10 17:31:40 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	four_octant(t_info *h, t_point p)
{
	p.er = p.dy;
	p.dy = p.er * 2;
	p.dx = p.dx * 2;
	while (1)
	{
		if (p.x1 > 0 && p.y1 > 0 && p.x1 < IMG_X && p.y1 < IMG_Y)
		{
			if ((p.y1 * h->visu.sl / 4) + p.x1 < IMG_Y * IMG_X
				&& (p.y1 * h->visu.sl / 4) + p.x1 > 0)
				h->visu.data[p.x1 + p.y1 * (h->visu.sl / 4)] = BROWN;
		}
		if ((p.y1 = p.y1 + 1) == p.y2)
			break ;
		if ((p.er = p.er - p.dx) < 0)
		{
			p.x1 = p.x1 + 1;
			p.er = p.er + p.dy;
		}
	}
}

void	three_octant(t_info *h, t_point p)
{
	p.er = p.dx;
	p.dx = p.er * 2;
	p.dy = p.dy * 2;
	while (1)
	{
		if (p.x1 > 0 && p.y1 > 0 && p.x1 < IMG_X && p.y1 < IMG_Y)
		{
			if ((p.y1 * h->visu.sl / 4) + p.x1 < IMG_Y * IMG_X
				&& (p.y1 * h->visu.sl / 4) + p.x1 > 0)
				h->visu.data[p.x1 + p.y1 * (h->visu.sl / 4)] = BROWN;
		}
		if ((p.x1 = p.x1 + 1) == p.x2)
			break ;
		if ((p.er = p.er - p.dy) < 0)
		{
			p.y1 = p.y1 + 1;
			p.er = p.er + p.dx;
		}
	}
}

void	two_octant(t_info *h, t_point p)
{
	p.er = p.dx;
	p.dx = p.er * 2;
	p.dy = p.dy * 2;
	while (1)
	{
		if (p.x1 > 0 && p.y1 > 0 && p.x1 < IMG_X && p.y1 < IMG_Y)
		{
			if ((p.y1 * h->visu.sl / 4) + p.x1 < IMG_Y * IMG_X
				&& (p.y1 * h->visu.sl / 4) + p.x1 > 0)
				h->visu.data[p.x1 + p.y1 * (h->visu.sl / 4)] = BROWN;
		}
		if ((p.x1 = p.x1 + 1) == p.x2)
			break ;
		if ((p.er = p.er + p.dy) < 0)
		{
			p.y1 = p.y1 - 1;
			p.er = p.er + p.dx;
		}
	}
}

void	one_octant(t_info *h, t_point p)
{
	p.er = p.dy;
	p.dy = p.er * 2;
	p.dx = p.dx * 2;
	while (1)
	{
		if (p.x1 > 0 && p.y1 > 0 && p.x1 < IMG_X && p.y1 < IMG_Y)
		{
			if ((p.y1 * h->visu.sl / 4) + p.x1 < IMG_Y * IMG_X
				&& (p.y1 * h->visu.sl / 4) + p.x1 > 0)
				h->visu.data[p.x1 + p.y1 * (h->visu.sl / 4)] = BROWN;
		}
		if ((p.y1 = p.y1 - 1) == p.y2)
			break ;
		if ((p.er = p.er + p.dx) > 0)
		{
			p.x1 = p.x1 + 1;
			p.er = p.er + p.dy;
		}
	}
}
