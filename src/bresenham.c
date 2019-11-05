/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:31:26 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/08/10 17:31:27 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	bresenham_horizontal(t_info *h, t_point p, int t)
{
	if (t == 0)
	{
		while (p.x1 <= p.x2)
		{
			if (p.x1 < IMG_X && p.x1 > 0 && p.y1 > 0 && p.y1 < IMG_Y
				&& (p.y1 * h->visu.sl / 4) + p.x1 < IMG_Y * IMG_X
				&& (p.y1 * h->visu.sl / 4) + p.x1 > 0)
				h->visu.data[(p.y1 * h->visu.sl / 4) + p.x1] = BROWN;
			p.x1++;
		}
	}
	else
	{
		while (p.x1 > p.x2)
		{
			if (p.x1 < IMG_X && p.x1 > 0 && p.y1 > 0 && p.y1 < IMG_Y
				&& (p.y1 * h->visu.sl / 4) + p.x1 < IMG_Y * IMG_X
				&& (p.y1 * h->visu.sl / 4) + p.x1 > 0)
				h->visu.data[(p.y1 * h->visu.sl / 4) + p.x1] = BROWN;
			p.x1--;
		}
	}
}

void	bresenham_vertical(t_info *h, t_point p)
{
	if ((p.dy = p.y2 - p.y1) != 0)
	{
		if (p.dy > 0)
		{
			while (p.y1 <= p.y2)
			{
				if (p.y1 > 0 && p.y1 < IMG_Y && p.x1 > 0 && p.x1 < IMG_X
					&& (p.y1 * h->visu.sl / 4) + p.x1 < IMG_Y * IMG_X
					&& (p.y1 * h->visu.sl / 4) + p.x1 > 0)
					h->visu.data[(p.y1 * h->visu.sl / 4) + p.x1] = BROWN;
				p.y1++;
			}
		}
		else if (p.dy < 0)
		{
			while (p.y1 > p.y2)
			{
				if (p.y1 > 0 && p.y1 < IMG_Y && p.x1 > 0 && p.x1 < IMG_X
					&& (p.y1 * h->visu.sl / 4) + p.x1 < IMG_Y * IMG_X
					&& (p.y1 * h->visu.sl / 4) + p.x1 > 0)
					h->visu.data[(p.y1 * h->visu.sl / 4) + p.x1] = BROWN;
				p.y1--;
			}
		}
	}
}

void	left_octant(t_info *handle, t_point p)
{
	if (p.dy > 0)
	{
		if (-1 * p.dx >= p.dy)
			six_octant(handle, p);
		else
			five_octant(handle, p);
	}
	else if (p.dy < 0 && p.dx < 0)
	{
		if (p.dx <= p.dy)
			seven_octant(handle, p);
		else if (p.dx > p.dy)
			eight_octant(handle, p);
	}
}

void	right_octant(t_info *handle, t_point p)
{
	if (p.dy > 0)
	{
		if (p.dx >= p.dy)
			three_octant(handle, p);
		else
			four_octant(handle, p);
	}
	else if (p.dy < 0 && p.dx > 0)
	{
		if (p.dx >= -1 * p.dy)
			two_octant(handle, p);
		else
			one_octant(handle, p);
	}
}

void	bresenham(t_info *handle, t_point p)
{
	if ((p.dx = p.x2 - p.x1) != 0)
	{
		if (p.dx > 0)
		{
			if ((p.dy = p.y2 - p.y1) != 0)
				right_octant(handle, p);
			else if (p.dy == 0)
				bresenham_horizontal(handle, p, 0);
		}
		else if (p.dx < 0)
		{
			if ((p.dy = p.y2 - p.y1) != 0)
				left_octant(handle, p);
			else if (p.dy == 0 && p.dx < 0)
				bresenham_horizontal(handle, p, 1);
		}
	}
	else if (p.dx == 0)
		bresenham_vertical(handle, p);
}
