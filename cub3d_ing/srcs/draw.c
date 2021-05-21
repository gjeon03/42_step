#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (y * img->size_l + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_verline(t_img *img, int y1, int y2, int color)
{
	int y;

	y = y1;
	while (y < y2)
	{
		my_mlx_pixel_put(mlx, img->x, y, color);
		y++;
	}
}

void	start_dir(char init_dir, t_info *info)
{
	if (init_dir == 'N')
	{
		info->window->dirX = -1.0;
		info->window->dirY = 0.0;
		info->window->planeX = 0.0;
		info->window->planeY = 0.66;
	}
	else if (init_dir == 'S')
	{
		info->window->dirX = 1.0;
		info->window->dirY = 0.0;
		info->window->planeX = 0.0;
		info->window->planeY = -0.66;
	}
	star_dir2(init_dir, mlx);
}

void	tar_dir2(char init_dir, t_mlx *mlx)
{
	if (init_dir == 'W')
	{
		info->window->dirX = 0.0;
		info->window->dirY = -1.0;
		info->window->planeX = -0.66;
		info->window->planeY = 0.0;
	}
	else if (init_dir == 'E')
	{
		info->window->dirX = 1.0;
		info->window->dirY = 1.0;
		info->window->planeX = 0.66;
		info->window->planeY = 0.0;
	}
}