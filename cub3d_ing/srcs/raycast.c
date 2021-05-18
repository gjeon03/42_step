#include "../include/cub3d.h"

int		ceiling_floor(t_info *info, int **buf)
{
	int	x;
	int	y;

	/*if (!(info->buf = malloc(sizeof(int) * info->window->height)))
		return (-1);
	x = 0;
	while (x < info->window->width)
	{
		if (!(info->buf[x] = malloc(sizeof(int) * info->window->width)))
			return (-1);
		x++;
	}*/
	x = 0;
	while (x < info->window->width)
	{
		y = 0;
		while (y < info->window->height)
		{
			buf[y][x] = info->color->c_color;
			buf[info->window->height - y - 1][x] = info->color->f_color;
			y++;
		}
		x++;
	}
}

void	ray_init(t_ray *ray, t_info *info, int x)
{
	ray.cameraX = (2 * x / (double)(info->window->width)) - 1;
	ray.rayDirX = info->window->dirX + info->window->planeX * cameraX;
	ray.rayDirY = info->window->dirY + info->window->planeY * cameraY;
	ray.mapX = (int)info->window->posX;
	ray.mapY = (int)info->window->posY;
	ray.deltaDistX = fabs(1 / rayDirX);
	ray.deltaDistY = fabs(1 / rayDirY);
}

void	get_step(t_ray *ray, t_info *info, int x)
{
	if (ray.rayDirX < 0)
	{
		ray.stepX = -1;
		ray.sideDistX = (info->window->posX - ray.mapX) * ray.deltaDistX;
	}
	else
	{
		ray.stepX = 1;
		ray.sideDistX = (ray.mapX + 1.0 - info->window->posX) * ray.deltaDistX;
	}
	if (ray.rayDirY < 0)
	{
		ray.stepY = -1;
		ray.sideDistY = (info->window->posY - ray.mapY) * ray.deltaDistY;
	}
	else
	{
		ray.stepY = 1;
		ray.sideDistY = (ray.mapY + 1.0 - info->window->posY) * ray.deltaDistY;
	}
}

void	wallhit(t_info *info, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray.sideDistX < ray.sideDistY)
		{
			ray.sideDistX += ray.deltaDistX;
			ray.mapX += ray.stepX;
			ray.side = 0;
		}
		else
		{
			ray.sideDistY += ray.deltaDistY;
			ray.mapY += ray.stepY;
			ray.side = 1;
		}
		if (info->map->tab[ray.mapX][ray.mapY] > 0)
			hit = 1;
	}
}

void	walldist(t_ray *ray)
{
	if (ray.side == 0)
		ray.perpWallDist = (ray.mapX - info->window->posX
				+ (1 - ray.stepX) / 2) / ray.rayDirX;
	else
		ray.perpWallDist = (ray.mapY - info->window->posY
				+ (1 - ray.stepY) / 2) / ray.rayDirY;
}

int		raycast(t_info *info, t_ray *ray, int **buf)
{
	int	x;

	ceiling_floor(info);
	x = 0;
	while (x < info->window->width)
	{
		ray_init(&ray, info, x);
		get_step(&ray, info, x);
		x++;
	}
	return (0);
}