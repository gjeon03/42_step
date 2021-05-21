#include "../include/cub3d.h"

void	player_movright(t_info *info)
{
	if (info->key->d)
	{
		if(!info->map->tab[(int)(info->window->posX
				+ info->window->planeX * info->window->moveSpeed)]
				[(int)(info->window->posY)])
			info->window->posX += info->window->planeX
					* info->window->moveSpeed;
		if(!info->map->tab[(int)(info->window->posX)]
				[(int)(info->window->posY + info->window->planeY
				* info->window->moveSpeed)])
			info->window->posY += info->window->planeY
					* info->window->moveSpeed;
	}
}

void	player_movleft(t_info *info)
{
	if (info->key->a)
	{
		if(!info->map->tab[(int)(info->window->posX
				- info->window->planeX * info->window->moveSpeed)]
				[(int)(info->window->posY)])
			info->window->posX -= info->window->planeX
					* info->window->moveSpeed;
		if(!info->map->tab[(int)(info->window->posX)]
				[(int)(info->window->posY - info->window->planeY
				* info->window->moveSpeed)])
			info->window->posY -= info->window->planeY
					* info->window->moveSpeed;
	}
}

void	player_movback(t_info *info)
{
	if (info->key->s)
	{
		if(!info->map->tab[(int)(info->window->posX
				- info->window->dirX * info->window->moveSpeed)]
				[(int)(info->window->posY)])
			info->window->posX += info->window->dirX
					* info->window->moveSpeed;
		if(!info->map->tab[(int)(info->window->posX)]
				[(int)(info->window->posY
				- info->window->dirY * info->window->moveSpeed)])
			info->window->posY += info->window->dirY
					* info->window->moveSpeed;
	}
}

void	player_movforward(t_info *info)
{
	if (info->key->w)
	{
		if(!info->map->tab[(int)(info->window->posX
				+ info->window->dirX * info->window->moveSpeed)]
				[(int)(info->window->posY)])
			info->window->posX += info->window->dirX
					* info->window->moveSpeed;
		if(!info->map->tab[(int)(info->window->posX)]
				[(int)(info->window->posY
				+ info->window->dirY * info->window->moveSpeed)])
			info->window->posY += info->window->dirY
					* info->window->moveSpeed;
	}
}

void	kwy_update(t_info *info)
{
	player_movforward(info);
	player_movback(info);
	player_movleft(info);
	player_movright(info);
	player_rotright(info);
	player_rotleft(info);
}