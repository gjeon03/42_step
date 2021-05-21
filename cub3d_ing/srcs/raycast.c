#include "../include/cub3d.h"

void	wallcalculation(t_info *info, t_ray *ray)
{
	ray->lineHeight = (int)(info->window->height / ray->perpWallDist);
	ray->drawStart = -ray->lineHeight / 2 + info->window->height / 2;
	if(ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + info->window->height / 2
	if(ray->drawEnd >= info->window->height)
		ray->drawEnd = info->window->height - 1;
}

void	dda_algorithm(t_info *info, t_ray *ray)
{
	ray->hit = 0;
	while (hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (info->map->tab[ray->mapX][ray->mapY] > 0)
			hit = 1;
	}
	if (ray->side == 0)
		ray->perpWallDist = (ray->mapX - info->window->posX
				+ (1 - ray->stepX) / 2) / ray->rayDirX;
	else
		ray->perpWallDist = (ray->mapY - info->window->posY
				+ (1 - ray->stepY) / 2) / ray->rayDirY;
}

void	dist_calculation(t_info *info, t_ray *ray)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (info->window->posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - info->window->posX)
				* ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (info->window->posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - info->window->posY)
				* ray->deltaDistY;
	}
}

void	ray_init(t_info *info, t_ray *ray, int x)
{
	ray->cameraX = (2 * x / (double)(info->window->width)) - 1;
	ray->rayDirX = info->window->dirX + info->window->planeX * ray->cameraX;
	ray->rayDirY = info->window->dirY + info->window->planeY * ray->cameraY;
	ray->mapX = (int)info->window->posX;
	ray->mapY = (int)info->window->posY;
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
}

int		raycast(t_info *info, t_ray *ray, t_img *img)
{
	img->x = 0;
	while (img->x < info->window->width)
	{
		ray_init(info, ray, img->x);
		dist_calculation(info, ray);
		dda_algorithm(info, ray);
		wallcalculation(info, ray);
		draw_verline(img, 0, ray->drawStart, info->color->c_color);
		draw_verline(img, ray->drawEnd + 1, info->window->height - 1, info->color->f_color);
		print_texture(info, ray, img->x, img);
		info->zBuffer[img->x] = ray->perpWallDist;
		img->x++;
	}
	return (0);
}