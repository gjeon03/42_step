#include "../include/cub3d.h"

void	wallcalculation(t_info *info)
{
	info->ray.lineHeight = (int)(info->config.height / info->ray.perpWallDist);
	info->ray.drawStart = -info->ray.lineHeight / 2 + info->config.height / 2;
	if(info->ray.drawStart < 0)
		info->ray.drawStart = 0;
	info->ray.drawEnd = info->ray.lineHeight / 2 + info->config.height / 2;
	if(info->ray.drawEnd >= info->config.height)
		info->ray.drawEnd = info->config.height - 1;
}

void	dda_algorithm(t_info *info)
{
	info->ray.hit = 0;
	int i = 0;
	while (info->ray.hit == 0)
	{
		if (info->ray.sideDistX < info->ray.sideDistY)
		{
			info->ray.sideDistX += info->ray.deltaDistX;
			info->ray.mapX += info->ray.stepX;
			info->ray.side = 0;
		}
		else
		{
			info->ray.sideDistY += info->ray.deltaDistY;
			info->ray.mapY += info->ray.stepY;
			info->ray.side = 1;
		}
		if (info->map.tab[info->ray.mapX][info->ray.mapY] == '1' && info->map.tab[info->ray.mapX][info->ray.mapY] != '2')
			info->ray.hit = 1;
	}
	if (info->ray.side == 0)
		info->ray.perpWallDist = (info->ray.mapX - info->config.posX
				+ (1 - info->ray.stepX) / 2) / info->ray.rayDirX;
	else
		info->ray.perpWallDist = (info->ray.mapY - info->config.posY
				+ (1 - info->ray.stepY) / 2) / info->ray.rayDirY;
}

void	dist_calculation(t_info *info)
{
	if (info->ray.rayDirX < 0)
	{
		info->ray.stepX = -1;
		info->ray.sideDistX = (info->config.posX - info->ray.mapX) * info->ray.deltaDistX;
	}	
	else
	{
		info->ray.stepX = 1;
		info->ray.sideDistX = (info->ray.mapX + 1.0 - info->config.posX) * info->ray.deltaDistX;
	}
	if (info->ray.rayDirY < 0)
	{
		info->ray.stepY = -1;
		info->ray.sideDistY = (info->config.posY - info->ray.mapY) * info->ray.deltaDistY;
	}
	else
	{
		info->ray.stepY = 1;
		info->ray.sideDistY = (info->ray.mapY + 1.0 - info->config.posY) * info->ray.deltaDistY;
	}
}

void	ray_init(t_info *info, int x)
{
	info->ray.cameraX = (2 * x / (double)(info->config.width)) - 1;
	info->ray.rayDirX = info->player.dirX + info->player.planeX * info->ray.cameraX;
	info->ray.rayDirY = info->player.dirY + info->player.planeY * info->ray.cameraX;
	info->ray.mapX = (int)info->config.posX;
	info->ray.mapY = (int)info->config.posY;
	info->ray.deltaDistX = fabs(1 / info->ray.rayDirX);
	info->ray.deltaDistY = fabs(1 / info->ray.rayDirY);
}

int		raycast(t_info *info)
{
	int	x;
	int y;

	celling_floot(info);
	x = 0;
	while (x < info->config.width)
	{
		ray_init(info, x);
		dist_calculation(info);
		dda_algorithm(info);
		wallcalculation(info);
		print_texture(info, x);
		info->zBuffer[x] = info->ray.perpWallDist;
		x++;
	}
	return (0);
}