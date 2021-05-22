#include "../include/cub3d.h"

void	player_movright(t_info *info)
{
	if (info->key.d == 1)
	{
		if(!((info->map.tab[(int)(info->config.posX
				+ info->player.planeX * info->player.moveSpeed)]
				[(int)(info->config.posY)]) - '0'))
			info->config.posX += info->player.planeX
					* info->player.moveSpeed;
		if(!((info->map.tab[(int)(info->config.posX)]
				[(int)(info->config.posY + info->player.planeY
				* info->player.moveSpeed)]) - '0'))
			info->config.posY += info->player.planeY
					* info->player.moveSpeed;
	}
}

void	player_movleft(t_info *info)
{
	if (info->key.a == 1)
	{
		if(!((info->map.tab[(int)(info->config.posX
				- info->player.planeX * info->player.moveSpeed)]
				[(int)(info->config.posY)]) - '0'))
			info->config.posX -= info->player.planeX
					* info->player.moveSpeed;
		if(!((info->map.tab[(int)(info->config.posX)]
				[(int)(info->config.posY - info->player.planeY
				* info->player.moveSpeed)]) - '0'))
			info->config.posY -= info->player.planeY
					* info->player.moveSpeed;
	}
}

void	player_movback(t_info *info)
{
	if (info->key.s == 1)
	{
		if(!((info->map.tab[(int)(info->config.posX
				- info->player.dirX * info->player.moveSpeed)]
				[(int)(info->config.posY)]) - '0'))
			info->config.posX -= info->player.dirX
					* info->player.moveSpeed;
		if(!((info->map.tab[(int)(info->config.posX)]
				[(int)(info->config.posY
				- info->player.dirY * info->player.moveSpeed)]) - '0'))
			info->config.posY -= info->player.dirY
					* info->player.moveSpeed;
	}
}

void	player_movforward(t_info *info)
{
	if (info->key.w == 1)
	{
		if(!((info->map.tab[(int)(info->config.posX
				+ info->player.dirX * info->player.moveSpeed)]
				[(int)(info->config.posY)]) - '0'))
			info->config.posX += info->player.dirX
					* info->player.moveSpeed;
		if(!((info->map.tab[(int)(info->config.posX)]
				[(int)(info->config.posY
				+ info->player.dirY * info->player.moveSpeed)]) - '0'))
			info->config.posY += info->player.dirY
					* info->player.moveSpeed;
	}
}

void	key_update(t_info *info)
{
	player_movforward(info);
	player_movback(info);
	player_movleft(info);
	player_movright(info);
	player_rotright(info);
	player_rotleft(info);
}