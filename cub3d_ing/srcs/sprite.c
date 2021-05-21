#include "../include/cub3d.h"

void			draw_sprites(t_info *info)
{
	int x;
	int y;
	int i;

	order_sprites(mlx);
	i = 0;
	while (i < info->window->sprite_count)
	{
		first_spritecalc(mlx, i);
		first_lastpix(mlx, i);
		x = mlx->sprt_firstx;
		while (x < mlx->sprt_lastx)
		{
			print_wall_tex(mlx, x, i);
			x++;
		}
		i++;
	}
}