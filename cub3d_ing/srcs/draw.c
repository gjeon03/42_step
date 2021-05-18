#include "../include/cub3d.h"

void	imageDraw(t_info *info, t_ray *ray, int **buf)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->window->height)
	{
		x = 0;
		while (x < info->window->width)
		{
			info->img.data[y * info->window->width + x] = buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}