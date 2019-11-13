/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:28:08 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/11/13 17:28:11 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	draw_edge(t_info *handle, t_graph *g, t_room *tmp, int i)
{
	t_visu	v;
	t_room	*tmp2;
	t_graph	*g2;

	g2 = g;
	v = handle->visu;
	while (g2->tab_neigh[i].begin)
	{
		v.p.x1 = tmp->x * v.pas - v.x_min * v.pas + v.pas / 2;
		v.p.y1 = tmp->y * v.pas - v.y_min * v.pas + v.pas / 2;
		tmp2 = handle->room;
		while (tmp2 && tmp2->index != g2->tab_neigh[i].begin->value)
			tmp2 = tmp2->next;
		v.p.x2 = tmp2->x * v.pas - v.x_min * v.pas + v.pas / 2;
		v.p.y2 = tmp2->y * v.pas - v.y_min * v.pas + v.pas / 2;
		draw_big_line(handle, v, 0);
		g2->tab_neigh[i].begin = g2->tab_neigh[i].begin->next;
	}
}

void	create_edge(t_info *handle)
{
	int		i;
	t_graph	*g;
	t_room	*tmp;

	i = 0;
	g = handle->graph;
	tmp = handle->room;
	while (i < g->nb_vertices)
	{
		tmp = handle->room;
		while (tmp && tmp->index != i)
			tmp = tmp->next;
		draw_edge(handle, g, tmp, i);
		++i;
	}
}

void	put_room_name(t_info *handle, t_visu v)
{
	t_room	*tmp;
	int		coordx;
	int		coordy;
	int		len;

	tmp = handle->room;
	while (tmp)
	{
		len = ft_strlen(tmp->name);
		coordx = v.pas * (tmp->x - v.x_min) - 10 * (len >= 5) + 4 * (len < 3);
		coordy = v.pas * (tmp->y - v.y_min) + 5;
		mlx_string_put(v.mlx, v.win, coordx, coordy, KAKI, tmp->name);
		tmp = tmp->next;
	}
}

void	create_room(t_info *handle, t_visu *visu, int x, int y)
{
	int		i;
	int		j;
	int		cor;
	t_room	*tmp;

	i = 0;
	tmp = handle->room;
	while (tmp && tmp->x != x && tmp->y != y)
		tmp = tmp->next;
	cor = (y - visu->y_min) * visu->pas * IMG_X + (x - visu->x_min) * visu->pas;
	while (i < visu->pas)
	{
		j = 0;
		while (j < visu->pas)
		{
			visu->data[cor + j] = BDX;
			++j;
		}
		cor += IMG_X;
		++i;
	}
}

void	create_background(t_info *handle, int i, int j)
{
	t_room	*tmp;

	create_edge(handle);
	while (i <= handle->visu.y_max)
	{
		j = handle->visu.x_min;
		while (j <= handle->visu.x_max)
		{
			tmp = handle->room;
			while (tmp)
			{
				if (i == tmp->y && j == tmp->x)
				{
					create_room(handle, &handle->visu, j, i);
					tmp = handle->room;
					break ;
				}
				tmp = tmp->next;
			}
			++j;
		}
		++i;
	}
	image_to_screen(handle, handle->visu, handle->nb_ants - 1);
}
