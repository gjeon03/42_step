#include "../include/cub3d.h"

void	player_rotright(t_info *info)
{
	double oldDirX;
	double oldPlaneX;

	if (info->key->r)
	{
		oldDirX = info->window->dirX;
		info->window->dirX = info->window->dirX
			* cos(-info->window->rotSpeed) - info->window->dirY
			* sin(-info->window->rotSpeed);
		info->window->dirY = oldDirX
			* sin(-info->window->rotSpeed) + info->window->dirY
			* cos(-info->window->rotSpeed);
		oldPlaneX = info->window->planeX;
		info->window->planeX = info->window->planeX
			* cos(-info->window->rotSpeed) - info->window->planeY
			* sin(-info->window->rotSpeed);
		info->window->planeY = oldPlaneX
			* sin(-info->window->rotSpeed) + info->window->planeY
			* cos(-info->window->rotSpeed);
	}
}

void	player_rotleft(t_info *info)
{
	double oldDirX;
	double oldPlaneX;

	if (info->key->l)
	{
		oldDirX = info->window->dirX;
		info->window->dirX = info->window->dirX
			* cos(info->window->rotSpeed) - info->window->dirY
			* sin(info->window->rotSpeed);
		info->window->dirY = oldDirX
			* sin(info->window->rotSpeed) + info->window->dirY
			* cos(info->window->rotSpeed);
		oldPlaneX = info->window->planeX;
		info->window->planeX = info->window->planeX
			* cos(info->window->rotSpeed) - info->window->planeY
			* sin(info->window->rotSpeed);
		info->window->planeY = oldPlaneX
			* sin(info->window->rotSpeed) + info->window->planeY
			* cos(info->window->rotSpeed);
	}
}