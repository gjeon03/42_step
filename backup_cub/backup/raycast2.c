#include "../include/cub3d.h"

void	tex_cody(t_info *info, t_ray *ray, int texNum, int texX, int x)
{
	double	step = 1.0 * T_HEIGHT / lineHeight;
	double	texPos = (drawStart - screenHeight / 2 + lineHeight / 2) * step;
	int		y;
	int		texY;

	y = ray->drawStart;
	while (y < drawEnd)
	{
		texY = (int)ray->texPos & (T_HEIGHT - 1);
		ray->texPos += ray->step;
		if (ray->side == 0 && ray->rayDirX > 0)
			ray->color = info->texture[1][T_HEIGHT * ray->texY + ray->texX];
		else if (ray->side == 0 && ray->rayDirX < 0)
			ray->color = info->texture[2][T_HEIGHT * ray->texY + ray->texX];
		else if (ray->side == 1 && ray->rayDirY > 0)
			ray->color = info->texture[3][T_HEIGHT * ray->texY + ray->texX];
		else
			ray->color = info->texture[4][T_HEIGHT * ray->texY + ray->texX];
		if (ray->side == 1)
			ray->color = (ray->color >> 1) & 8355711;
		info->buf[y][x] = ray->color;
		y++;
	}
	info->zBuffer[x] = perpWallDist;
}

void	tex_choice(t_info *info, t_ray *ray, int x)
{
	int		texNum;
	double	wallX;
	int		texX;

	texNum = info->map->tab[ray->mapX][ray->mapY] - 1;
	if (side == 0)
		wallX = info->window->posY + ray->perpWallDist * ray->rayDirY;
	else
		wallX = info->window->posX + ray->perpWallDist * rayDirX;
	wallX -= floor(wallX);
	texX = (int)(wallX * (double)T_WIDTH);
	if (ray->side == 0 && ray->rayDirX > 0)
		texX = T_WIDTH - texX - 1;
	if (ray->side == 1 && ray->rayDirY < 0)
		texX = T_WIDTH - texX - 1;
	tex_cody(info, ray, texNumm, texX), x;
}

void	lineHeight(t_info *info, t_ray *ray)
{
	ray->lineHeight = (int)(info->window->height / ray->perpWallDist);
	ray->drawStart = -ray->lineHeight / 2 + info->window->height / 2;
	ray->drawEnd = ray->lineHeight / 2 + info->window->height / 2
	if(ray->drawStart < 0)
		ray->drawStart = 0;
	if(ray->drawEnd >= info->window->height)
		ray->drawEnd = info->window->height - 1;
}