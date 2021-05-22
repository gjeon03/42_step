#include "../include/cub3d.h"

void	imageDraw(t_info *info)
{
	int x;
	int	y;

	y = 0;
	while (y < info->config.height)
	{
		x = 0;
		while (x < info->config.width)
		{
			info->img.data[y * info->config.width + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	start_dir(t_info *info)
{
	info->player.moveSpeed = 0.05;
	info->player.rotSpeed = 0.05;
	if (info->config.dir == 'N')
	{
		info->player.dirX = -1.0;
		info->player.dirY = 0.0;
		info->player.planeX = 0.0;
		info->player.planeY = 0.66;
	}
	else if (info->config.dir == 'S')
	{
		info->player.dirX = 1.0;
		info->player.dirY = 0.0;
		info->player.planeX = 0.0;
		info->player.planeY = -0.66;
	}
	start_dir2(info);
}

void	start_dir2(t_info *info)
{
	if (info->config.dir == 'W')
	{
		info->player.dirX = 0.0;
		info->player.dirY = -1.0;
		info->player.planeX = -0.66;
		info->player.planeY = 0.0;
	}
	else if (info->config.dir == 'E')
	{
		info->player.dirX = 0.0;
		info->player.dirY = 1.0;
		info->player.planeX = 0.66;
		info->player.planeY = 0.0;
	}
}