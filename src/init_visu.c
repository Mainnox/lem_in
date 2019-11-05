#include "lem_in.h"

int		init_rpasu(t_info *handle, t_visu *v)
{
	int		i;
	t_print	print;

	i = 0;
	print = handle->print;
//set_print(handle);leaks->faire une fct create qui malloc et set qui set à 0
	if (!(v->rpasu = (int **)ft_memalloc(sizeof(int *) * print.max_flow)))
		return (0);
	while (i < print.max_flow)
	{
		if (!(v->rpasu[i] = (int *)ft_memalloc(sizeof(int) * print.pasu[i][0])))
			return (0);
		++i;
	}
	return (1);
}

void	init_mlx(t_info *handle)
{
	t_visu	tmp;

	tmp.mlx = mlx_init();
	tmp.win = mlx_new_window(tmp.mlx, WIN_X, WIN_Y, TITLE);
	tmp.img = mlx_new_image(tmp.mlx, IMG_X, IMG_Y);
	tmp.data = (int *)mlx_get_data_addr(tmp.img, &tmp.bpp, &tmp.sl, &tmp.edn);
	tmp.data = ft_memset(tmp.data, TRANS, sizeof(int) * IMG_X * IMG_Y);
	tmp.img2 = mlx_xpm_file_to_image(tmp.mlx, XPM_PATH, &tmp.h, &tmp.w);
	tmp.img3 = mlx_xpm_file_to_image(tmp.mlx, XPM2_PATH, &tmp.h2, &tmp.w2);
	tmp.img4 = mlx_new_image(tmp.mlx, IMG_X, IMG_Y);
	tmp.data4 = (int *)mlx_get_data_addr(tmp.img4, &tmp.bpp, &tmp.sl4, &tmp.edn);
	tmp.data4 = ft_memset(tmp.data4, TRANS, sizeof(int) * IMG_X * IMG_Y);
	tmp.img5 = mlx_new_image(tmp.mlx, 100, 25);
	tmp.data5 = (int *)mlx_get_data_addr(tmp.img5, &tmp.bpp, &tmp.sl5, &tmp.edn);
	tmp.data5 = ft_memset(tmp.data4, BLACK, sizeof(int) * 2500);
	handle->visu = tmp;
}

void	init_point(t_visu *visu)
{
	visu->p.x1 = 0;
	visu->p.x2 = 0;
	visu->p.y1 = 0;
	visu->p.y2 = 0;
	visu->p.dx = 0;
	visu->p.dy = 0;
	visu->p.er = 0;
}

void	find_extrem(t_visu *visu, t_room *tmp)
{
	visu->x_min = INT_MAX;
	visu->x_max = INT_MIN;
	visu->y_min = INT_MAX;
	visu->y_max = INT_MIN;
	while (tmp)
	{
		if (visu->x_min > tmp->x)
			visu->x_min = tmp->x;
		if (visu->x_max < tmp->x)
			visu->x_max = tmp->x;
		if (visu->y_min > tmp->y)
			visu->y_min = tmp->y;
		if (visu->y_max < tmp->y)
			visu->y_max = tmp->y;
		tmp = tmp->next;
	}
	visu->x_min -= BORDURE;
	visu->x_max += BORDURE;
	visu->y_min -= BORDURE;
	visu->y_max += BORDURE;
}

void	init_visu(t_info *handle, t_visu *visu)
{
	t_room	*tmp;

	tmp = handle->room;
	find_extrem(visu, tmp);
	visu->pause = 0;
	visu->nb_x = visu->x_max - visu->x_min + 1;
	visu->nb_y = visu->y_max - visu->y_min + 1;//attention au 0
	if (visu->nb_x != 0)
		visu->pas = IMG_X / visu->nb_x;//attention au 0
	if (visu->nb_y != 0 && IMG_Y / visu->nb_y < visu->pas)
		visu->pas = IMG_Y / visu->nb_y;
	init_point(visu);
}
