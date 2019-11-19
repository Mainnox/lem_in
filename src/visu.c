/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:33:21 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/11/19 00:42:12 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		key_event(int key, t_info *handle)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_SPACE)
		handle->visu.pause = handle->visu.pause == 0 ? 1 : 0;
	return (1);
}

void	draw_big_line(t_info *handle, t_visu v, int i)
{
	int		pas;

	pas = 1;
	bresenham(handle, v.p);
	while (i < EDGE_W)
	{
		if (v.p.y2 - v.p.y1 == 0)
		{
			v.p.y1 -= pas;
			v.p.y2 -= pas;
		}
		v.p.x1 -= pas;
		v.p.x2 -= pas++;
		bresenham(handle, v.p);
		if (v.p.y2 - v.p.y1 == 0)
		{
			v.p.y1 += pas;
			v.p.y2 += pas;
		}
		v.p.x1 += pas;
		v.p.x2 += pas++;
		bresenham(handle, v.p);
		++i;
	}
}

void	image_to_screen(t_info *handle, t_visu v, int ant)
{
	char	*itoa;

	itoa = ft_itoa(ant + 1);
	mlx_put_image_to_window(v.mlx, v.win, v.img2, 0, 0);
	mlx_put_image_to_window(v.mlx, v.win, v.img, 0, 0);
	mlx_put_image_to_window(v.mlx, v.win, v.img5, SIZE_SCREEN + 135, 180);
	mlx_string_put(v.mlx, v.win, SIZE_SCREEN + 140, 185, WHITE, itoa);
	put_room_name(handle, v);
	mlx_put_image_to_window(v.mlx, v.win, v.img4, 0, 0);
	if (itoa)
		ft_strdel(&itoa);
}

int		visu(t_info *handle, int ant)
{
	t_visu	v;

	(void)ant;
	handle->print.ant = ant;
	v = handle->visu;
	if (handle->init_visu == 1)
	{
		init_mlx(handle);
		if (init_rpasu(handle, &handle->visu) == 0)
			return (0);
		init_visu(handle, &handle->visu);
		create_pannel(handle);
		create_background(handle, handle->visu.y_min, 0);
		handle->init_visu = 2;
	}
	create_movement(handle, 0);
	if (mlx_key_hook(handle->visu.win, key_event, handle) == 0)
		return (0);
	return (1);
}
