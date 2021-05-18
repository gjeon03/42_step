#include "../include/cub3d.h"

void	lineHeight(t_info *info, t_ray *ray)
{
	int	lineHeight;

	lineHeight = (int)(info->window->height / ray.perpWallDist);
	ray.drawStart = -lineHeight / 2 + info->window->height / 2;
	ray.drawEnd = lineHeight / 2 + info->window->height / 2
	if(ray.drawStart < 0)
		ray.drawStart = 0;
	if(ray.drawEnd >= info->window->height)
		ray.drawEnd = info->window->height - 1;
}