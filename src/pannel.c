#include "lem_in.h"

void    create_bordure(t_visu v, int i)
{
	while (++i < SIZE_SCREEN)
	{
		mlx_pixel_put(v.mlx, v.win, SIZE_SCREEN + 1, i, BROWN);
		mlx_pixel_put(v.mlx, v.win, SIZE_SCREEN + 2, i, BROWN);
		mlx_pixel_put(v.mlx, v.win, SIZE_SCREEN + 3, i, BROWN);
		mlx_pixel_put(v.mlx, v.win, SIZE_SCREEN + 4, i, BROWN);
		mlx_pixel_put(v.mlx, v.win, SIZE_SCREEN + 5, i, BROWN);
	}
	i = -1;
	while (++i < 60)
	{
		mlx_pixel_put(v.mlx, v.win, SIZE_SCREEN + 55, i + 155, WHITE);
		mlx_pixel_put(v.mlx, v.win, SIZE_SCREEN + 56, i + 155, WHITE);
		mlx_pixel_put(v.mlx, v.win, SIZE_SCREEN + 250, i + 155, WHITE);
		mlx_pixel_put(v.mlx, v.win, SIZE_SCREEN + 251, i + 155, WHITE);
	}
	i = -1;
	while (++i < 196)
	{
		mlx_pixel_put(v.mlx, v.win, SIZE_SCREEN + 55 + i, 155, WHITE);
		mlx_pixel_put(v.mlx, v.win, SIZE_SCREEN + 56 + i, 156, WHITE);
		mlx_pixel_put(v.mlx, v.win, SIZE_SCREEN + 55 + i, 216, WHITE);
		mlx_pixel_put(v.mlx, v.win, SIZE_SCREEN + 56 + i, 215, WHITE);
	}
}

void    create_pannel(t_info *handle)
{
	int             i;
	t_visu  v;

	i = 0;
	v = handle->visu;
	create_bordure(handle->visu, -1);
	mlx_string_put(v.mlx, v.win, SIZE_SCREEN + PANNEL_SIZE / 5
			, SIZE_SCREEN - 40, YELLOW, SIGNATURE);
	mlx_string_put(v.mlx, v.win, SIZE_SCREEN + 70, 30, WHITE, TXT_ESC);
	mlx_string_put(v.mlx, v.win, SIZE_SCREEN + 70, 55, WHITE, TXT_SPACE);
	mlx_string_put(v.mlx, v.win, SIZE_SCREEN + 70, 160, WHITE, TXT_N_ANT);
	mlx_put_image_to_window(v.mlx, v.win, v.img3, SIZE_SCREEN + 110, 270);
}
