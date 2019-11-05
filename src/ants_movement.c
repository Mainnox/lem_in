#include "lem_in.h"

void	salut(void)
{while(1);}

void	copy_pos_ant_to_rpasu(t_info *h)
{
	int		i;
	int		j;
	t_visu	v;

	v = h->visu;
	i = 0;
	while (i < h->print.max_flow)
	{
		j = 0;
		while (j < h->print.pasu[i][0])
		{
			v.rpasu[i][j] = h->print.pos_ants[i][j];
			++j;
		}
		++i;
	}
}

t_room	*fix_index(t_info *h, int j, int i, int b)
{
	t_room	*tmp;
	t_room	*tmp1;

	tmp = h->room;
	tmp1 = h->room;
	if (j == 0)
	{
		while (tmp && tmp->index != 0)
			tmp = tmp->next;
		while (tmp1 && tmp1->index != h->print.pasu[i][j + 1])
			tmp1 = tmp1->next;
	}
	else if (j == h->print.pasu[i][0] - 1)
	{
		while (tmp && tmp->index != h->print.pasu[i][j])
			tmp = tmp->next;
		while (tmp1 && tmp1->index != 1)
			tmp1 = tmp1->next;
	}
	else
	{
		while (tmp && tmp->index != h->print.pasu[i][j])
			tmp = tmp->next;
		while (tmp1 && tmp1->index != h->print.pasu[i][j + 1])
			tmp1 = tmp1->next;
	}
	return (b == 0 ? tmp : tmp1);
}

/*
**		fonction qui cree une fourmis en position (x, y)
*/

void	create_ant(t_info *handle, t_visu *v, int x, int y)
{
	int		i;
	int		j;
	int		coord;

	i = 0;
	(void)handle;
	coord = (y + v->pas / 2 - SIZE_ANT / 2) * IMG_X + (x + v->pas / 2 - SIZE_ANT / 2);
	while (i < SIZE_ANT)
	{
		j = 0;
		while (j < SIZE_ANT)
		{
			if (coord + j >= 0 && coord + j < IMG_X * IMG_Y)
				v->data4[coord + j] = YELLOW;
			++j;
		}
		coord += IMG_X;
		++i;
	}
}

void	create_ant_movement(t_info *h, int f, int i, int j)
{
	int		pasx;
	int		pasy;
	t_room	*tmp;
	t_room	*tmp1;
	t_point	p;

	tmp = fix_index(h, j, i, 0);
	tmp1 = fix_index(h, j, i, 1);
	p.x1 = h->visu.pas * (tmp->x - h->visu.x_min);
	p.y1 = h->visu.pas * (tmp->y - h->visu.y_min);
	p.x2 = h->visu.pas * (tmp1->x - h->visu.x_min);
	p.y2 = h->visu.pas * (tmp1->y - h->visu.y_min);
	pasx = (p.x2 - p.x1) / FRAME;
	pasy = (p.y2 - p.y1) / FRAME;
	create_ant(h, &h->visu, p.x1 + f * pasx, p.y1 + f * pasy);
//	ft_printf("index0 %d\n", tmp->index);
//	ft_printf("index1 %d\n", tmp1->index);
//	ft_printf("p.x1 %d\n", p.x1);
//	ft_printf("p.y1 %d\n", p.y1);
//	ft_printf("pas x -> %d\n", pasx);
//	ft_printf("pas y -> %d\n------------------------------------\n\n", pasy);
}

void	create_movement(t_info *h)
{
	int		f;
	int		i;
	int		j;

	f = 0;
	while (f <= FRAME)
	{
		i = 0;
		while (i < h->print.max_flow)
		{
			j = 0;
			while (j < h->print.pasu[i][0])
			{
				if (h->print.pos_ants[i][j] != h->visu.rpasu[i][j] && h->print.pos_ants[i][j] != 0)
					create_ant_movement(h, f, i, j);
//				h->visu.rpasu[i][j] = h->print.pos_ants[i][j];
				++j;
			}
			++i;
		}
		image_to_screen(h, h->visu, h->nb_ants - h->print.ant);
		mlx_do_sync(h->visu.mlx);
		ft_memset(h->visu.data4, TRANS, sizeof(int) * IMG_X * IMG_Y);
		++f;
	}
	copy_pos_ant_to_rpasu(h);
	image_to_screen(h, h->visu, h->nb_ants - h->print.ant);
}
