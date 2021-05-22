#include "../include/cub3d.h"

void	player_rotright(t_info *info)
{
	double oldDirX;
	double oldPlaneX;

	if (info->key.r == 1)
	{
		oldDirX = info->player.dirX;
		info->player.dirX = info->player.dirX
			* cos(-info->player.rotSpeed) - info->player.dirY
			* sin(-info->player.rotSpeed);
		info->player.dirY = oldDirX
			* sin(-info->player.rotSpeed) + info->player.dirY
			* cos(-info->player.rotSpeed);
		oldPlaneX = info->player.planeX;
		info->player.planeX = info->player.planeX
			* cos(-info->player.rotSpeed) - info->player.planeY
			* sin(-info->player.rotSpeed);
		info->player.planeY = oldPlaneX
			* sin(-info->player.rotSpeed) + info->player.planeY
			* cos(-info->player.rotSpeed);
	}
}

void	player_rotleft(t_info *info)
{
	double oldDirX;
	double oldPlaneX;

	if (info->key.l == 1)
	{
		oldDirX = info->player.dirX;
		info->player.dirX = info->player.dirX
			* cos(info->player.rotSpeed) - info->player.dirY
			* sin(info->player.rotSpeed);
		info->player.dirY = oldDirX
			* sin(info->player.rotSpeed) + info->player.dirY
			* cos(info->player.rotSpeed);
		oldPlaneX = info->player.planeX;
		info->player.planeX = info->player.planeX
			* cos(info->player.rotSpeed) - info->player.planeY
			* sin(info->player.rotSpeed);
		info->player.planeY = oldPlaneX
			* sin(info->player.rotSpeed) + info->player.planeY
			* cos(info->player.rotSpeed);
	}
}